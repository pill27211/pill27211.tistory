#include <bits/stdc++.h>
#define r int n, int s, int e, int p, int q
#define ll long long
#define N 100001
using namespace std;

vector <ll> Gr[N], G[N], pseg[1 << 18];
vector <int> seg[1 << 18];
int D[N], S[N], P[N], C[N];
int top[N], in[N];
ll n, q, o, i, j;

void f0()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> q;
	for (i = 1; i <= n; cin >> C[i++]);
	for (int o(1); o < n; o++)
		cin >> i >> j, Gr[i].push_back(j), Gr[j].push_back(i);
}
void f1(int p)
{
	S[p] = 1;
	for (int i : Gr[p])
		if (!S[i])
		{
			D[i] = D[p] + 1;
			P[i] = p;
			f1(i);
			S[p] += S[i];
			G[p].push_back(i);
			if (S[i] > S[G[p][0]]) swap(G[p][0], G[p].back());
		}
}
void f2(int p)
{
	in[p] = ++o;
	for (int i : G[p])
		top[i] = i == G[p][0] ? top[p] : i, f2(i);
}
void f3(r)
{
	if (s > p || e < p) return;
	seg[n].push_back(q);
	if (s ^ e)
		f3(n << 1, s, (s + e) >> 1, p, q), f3(n << 1 | 1, ((s + e) >> 1) + 1, e, p, q);
}
ll f4(r)
{
	if (s > q || e < p) return 0;
	if (s >= p && e <= q)
	{
		ll x = lower_bound(seg[n].begin(), seg[n].end(), i) - seg[n].begin();
		ll y = upper_bound(seg[n].begin(), seg[n].end(), j) - seg[n].begin();
		return (y ? pseg[n][y - 1] : 0) - (x ? pseg[n][x - 1] : 0);
	}
	return f4(n << 1, s, (s + e) >> 1, p, q) + f4(n << 1 | 1, ((s + e) >> 1) + 1, e, p, q);
}
ll f5(int x, int y)
{
	ll t{};
	while (top[x] ^ top[y])
	{
		if (D[top[x]] < D[top[y]]) swap(x, y);
		t += f4(1, 1, n, in[top[x]], in[x]);
		x = P[top[x]];
	}
	if (D[x] > D[y]) swap(x, y);
	return t + f4(1, 1, n, in[x], in[y]);
}
void sv()
{
	for (i = 1; i <= n; i++)
		f3(1, 1, n, in[i], C[i]);
	for (i = 0; i < (1 << 18); i++)
	{
		sort(seg[i].begin(), seg[i].end());
		for (o = j = 0; j < (int)seg[i].size(); j++)
			o += seg[i][j], pseg[i].push_back(o);
	}
	for (int x, y; q--;)
		cin >> x >> y >> i >> j, cout << f5(x, y) << '\n';
}
int main()
{
	f0();
	f1(1), f2(1);
	sv();
}
