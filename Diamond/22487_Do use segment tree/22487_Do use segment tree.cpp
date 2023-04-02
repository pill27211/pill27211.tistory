#include <bits/stdc++.h>
#define r int n, int s, int e
#define ll long long
#define N 200001
using namespace std;

struct T { ll ls, rs, ps, ms; } seg[1 << 19];
vector <int> Gr[N], G[N];
int top[N], in[N], C[N];
int D[N], P[N], S[N];
int n, q, e, i, j, M(-1e9), lz[1 << 19];

T f(T L, T R) {return { max({L.ls, L.ps + R.ls}), max({R.rs, R.ps + L.rs}), L.ps + R.ps, max({ L.ms, R.ms, L.rs + R.ls }) };}
void f0()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	fill(lz, lz + (1 << 19), M); seg[0] = { M, M, 0, M };
	for (cin >> n >> q; j < n; cin >> C[++j]);
	for (int o{}; o++ < n - 1;)
		cin >> i >> j, Gr[i].push_back(j), Gr[j].push_back(i);
}
void f1(int p)
{
	S[p] = 1;
	for (int& a : Gr[p])
		if (!S[a])
		{
			D[a] = D[p] + 1;
			P[a] = p;
			f1(a);
			S[p] += S[a];
			G[p].push_back(a);
			if (S[a] > S[G[p][0]]) swap(G[p][0], G[p].back());
		}
}
void f2(int p)
{
	in[p] = ++e;
	for (int& a : G[p])
		top[a] = a == G[p][0] ? top[p] : a, f2(a);
}
void f3(r)
{
	if (lz[n] ^ M)
	{
		if (s ^ e)
			lz[n << 1] = lz[n], lz[n << 1 | 1] = lz[n];
		seg[n].ps = lz[n] * (e - s + 1);
		seg[n].ls = seg[n].rs = seg[n].ms = max(seg[n].ps, (ll)lz[n]);
		lz[n] = M;
	}
}
T f4(r, int p, int q, int w)
{
	f3(n, s, e);
	if (s > q || e < p) return seg[n];
	if (s >= p && e <= q) return (lz[n] = w, f3(n, s, e)), seg[n];
	return seg[n] = f(f4(n << 1, s, (s + e) >> 1, p, q, w), f4(n << 1 | 1, ((s + e) >> 1) + 1, e, p, q, w));
}
T f5(r, int p, int q)
{
	f3(n, s, e);
	if (s > q || e < p) return seg[0];
	if (s >= p && e <= q) return seg[n];
	return f(f5(n << 1, s, (s + e) >> 1, p, q), f5(n << 1 | 1, ((s + e) >> 1) + 1, e, p, q));
}
void f6(int p, int q, int w)
{
	while (top[p] ^ top[q])
	{
		if (D[top[p]] < D[top[q]]) swap(p, q);
		f4(1, 1, n, in[top[p]], in[p], w);
		p = P[top[p]];
	}
	if (D[p] > D[q]) swap(p, q);
	f4(1, 1, n, in[p], in[q], w);
}
ll f7(int p, int q)
{
	T x(seg[0]), y(seg[0]);
	while (top[p] ^ top[q])
	{
		if (D[top[p]] > D[top[q]])
			x = f(f5(1, 1, n, in[top[p]], in[p]), x), p = P[top[p]];
		else
			y = f(f5(1, 1, n, in[top[q]], in[q]), y), q = P[top[q]];
	}
	if (D[p] > D[q]) swap(p, q), swap(x, y);
	swap(x.ls, x.rs);
	return f(x, f(f5(1, 1, n, in[p], in[q]), y)).ms;
}
void sv()
{
	for (i = 1; i <= n; i++) f4(1, 1, n, in[i], in[i], C[i]);
	for (int o, k; q--;)
		if (cin >> o >> i >> j >> k; o & 1) f6(i, j, k);
		else cout << f7(i, j) << '\n';
}
int main()
{
	f0();
	f1(1); f2(1);
	sv();
}
