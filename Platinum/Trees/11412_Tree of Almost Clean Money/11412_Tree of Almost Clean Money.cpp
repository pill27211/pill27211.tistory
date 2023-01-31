#include <bits/stdc++.h>
#define ll long long
#define N 500001
using namespace std;

vector <int> Gr[N], G[N];
int top[N], in[N], out[N], xdp[1001];
int P[N], S[N], D[N], C[N];
ll seg[N], ydp[1001];
ll n, q, i, j, Q[10];

ll x(ll p)
{
	if (p == 1) return Q[2];
	if (xdp[p]) return xdp[p];
	return xdp[p] = (Q[4] * x(p - 1) + Q[5]) % n;
}
ll y(ll p)
{
	if (p == 1) return Q[3];
	if (ydp[p]) return ydp[p];
	return ydp[p] = (Q[6] * y(p - 1) + Q[7]) % ((ll)1e9 + 7);
}
void f0()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (ll o{ 1 }; o < n; o++)
	{
		cin >> i >> j;
		i++, j++;
		Gr[i].push_back(j), Gr[j].push_back(i);
	}
	for (i = 1; i <= n; cin >> C[i++]);
}
void f1(ll p)
{
	S[p] = 1;
	for (int& i : Gr[p])
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
	in[p] = ++q;
	for (int& i : G[p])
		top[i] = i == G[p][0] ? top[p] : i, f2(i);
	out[p] = q;
}
void f3(ll p, ll q)
{
	while (p <= N - 1)
		seg[p] += q, p += p & -p;
}
ll f4(ll p)
{
	ll r{};
	while (p)
		r += seg[p], p -= p & -p;
	return r;
}
ll f6(ll p, ll q)
{
	ll r{};
	while (top[p] ^ top[q])
	{
		if (D[top[p]] < D[top[q]]) swap(p, q);
		r += (f4(in[p]) - f4(in[top[p]] - 1));
		p = P[top[p]];
	}
	if (D[p] > D[q]) swap(p, q);
	return r + f4(in[q]) - f4(in[p] - 1);
}
void sv()
{
	for (i = 1; i <= n; i++) f3(in[i], C[i]);
	cin >> q;
	while (q--)
	{
		for (i = 1; i < 10; cin >> Q[i++]);
		for (i = 1; i <= Q[1]; i++)
			f3(in[x(i) + 1], y(i));
		cout << f6(Q[8] + 1, Q[9] + 1) << '\n';
		memset(xdp, 0, sizeof xdp); memset(ydp, 0, sizeof ydp);
	}
}
int main()
{
	f0();
	f1(1); f2(1);
	sv();
}
