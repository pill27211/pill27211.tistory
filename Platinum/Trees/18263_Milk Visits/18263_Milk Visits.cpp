#include<bits/stdc++.h>
#define N 100001
using namespace std;

vector <int> Gr[N], G[N], seg[1 << 18];
int C[N], P[N], S[N], D[N];
int top[N], in[N];
int n, q, i, j, o;
string an;

void f0()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> q;
	for (int i(1); i <= n; cin >> C[i++]);
	for (int o{}; ++o < n;)
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
void f3(int n, int s, int e, int p, int q)
{
	if (s > p || e < p) return;
	seg[n].push_back(q);
	if (s ^ e)
		f3(n << 1, s, (s + e) >> 1, p, q), f3(n << 1 | 1, ((s + e) >> 1) + 1, e, p, q);
}
int f4(int n, int s, int e, int p, int q)
{
	if (s > q || e < p) return 0;
	if (s >= p && e <= q)
	{
		auto it(lower_bound(seg[n].begin(), seg[n].end(), o));
		return it != seg[n].end() && *it == o ? 1 : 0;
	}
	return f4(n << 1, s, (s + e) >> 1, p, q) + f4(n << 1 | 1, ((s + e) >> 1) + 1, e, p, q);
}
char f5()
{
	while (top[i] ^ top[j])
	{
		if (D[top[i]] < D[top[j]]) swap(i, j);
		if (f4(1, 1, n, in[top[i]], in[i])) return '1';
		i = P[top[i]];
	}
	if (D[i] > D[j]) swap(i, j);
	return f4(1, 1, n, in[i], in[j]) ? '1' : '0';
}
void sv()
{
	for (i = 1; i <= n; i++) f3(1, 1, n, in[i], C[i]);
	for (i = 0; i < (1 << 18); i++) sort(seg[i].begin(), seg[i].end());
	while (q--)
		cin >> i >> j >> o, an += f5();
	cout << an;
}
int main()
{
	f0();
	f1(1); f2(1);
	sv();
}
