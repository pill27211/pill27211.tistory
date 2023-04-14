#include<bits/stdc++.h>
#define r ll n, ll s, ll e
#define ll long long
#define N 100001
using namespace std;

struct T { ll ls, rs, ps, ms; }seg[1 << 18];
vector <int> Gr[N], G[N];
int top[N], in[N], lz[1 << 18];
int P[N], D[N], S[N], C[N];
ll n, q, i, j, M(-1e9);

T f(T x, T y) { return { max(x.ls, x.ps + y.ls), max(y.rs, y.ps + x.rs), x.ps + y.ps, max({x.ms, y.ms, x.rs + y.ls}) }; }
void f0()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	fill(lz, lz + (1 << 18), M); seg[n] = { M, M, 0, M };
	for (cin >> n; ++i <= n; cin >> C[i]);
	for (int o{}; o++ < n - 1;)
		cin >> i >> j, Gr[i].push_back(j), Gr[j].push_back(i);
}
void f1(int p)
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
}
void f3(r)
{
	if (lz[n] == M) return;
	if (s ^ e) lz[n << 1] = lz[n << 1 | 1] = lz[n];
	seg[n].ps = lz[n] * (e - s + 1);
	seg[n].ls = seg[n].rs = seg[n].ms = max(0LL, seg[n].ps);
	lz[n] = M;
}
T f4(r, ll p, ll q, ll k)
{
	f3(n, s, e);
	if (s > q || e < p) return seg[n];
	if (s >= p && e <= q) return (lz[n] = k, f3(n, s, e)), seg[n];
	T L(f4(n << 1, s, (s + e) >> 1, p, q, k)), R(f4(n << 1 | 1, ((s + e) >> 1) + 1, e, p, q, k));
	return seg[n] = f(L, R);
}
T f5(r, ll p, ll q)
{
	f3(n, s, e);
	if (s > q || e < p) return seg[0];
	if (s >= p && e <= q) return seg[n];
	T L(f5(n << 1, s, (s + e) >> 1, p, q)), R(f5(n << 1 | 1, ((s + e) >> 1) + 1, e, p, q));
	return f(L, R);
}
void f6(ll x, ll y, ll w)
{
	while (top[x] ^ top[y])
	{
		if (D[top[x]] < D[top[y]]) swap(x, y);
		f4(1, 1, n, in[top[x]], in[x], w);
		x = P[top[x]];
	}
	if (D[x] > D[y]) swap(x, y);
	f4(1, 1, n, in[x], in[y], w);
}
ll f7(ll x, ll y)
{
	T p(seg[0]), q(seg[0]);
	while (top[x] ^ top[y])
		D[top[x]] > D[top[y]] ? p = f(f5(1, 1, n, in[top[x]], in[x]), p), x = P[top[x]] : (q = f(f5(1, 1, n, in[top[y]], in[y]), q), y = P[top[y]]);
	if (D[x] > D[y]) swap(x, y), swap(p, q);
	swap(p.ls, p.rs);
	return f(p, f(f5(1, 1, n, in[x], in[y]), q)).ms;
}
void sv()
{
	for (cin >> q, i = 1; i <= n; i++) f6(i, i, C[i]);
	for (ll o, w; q--;)
		if (cin >> o >> i >> j; o & 1) cout << f7(i, j) << '\n';
		else cin >> w, f6(i, j, w);
}
int main()
{
	f0();
	f1(1); f2(1);
	sv();
}
