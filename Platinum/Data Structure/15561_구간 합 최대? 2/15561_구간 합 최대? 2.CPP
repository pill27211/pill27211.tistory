#include<bits/stdc++.h>
#define r ll n, ll s, ll e, ll p, ll q
#define ll long long
using namespace std;

struct S { ll ls, rs, ps, ms; }seg[1 << 18];
ll n, q, u, v, M(-1e18);

S f1(r)
{
	if (s > p || e < p) return seg[n];
	if (s == e) return seg[n] = { q, q, q, q };
	ll m((s + e) >> 1);
	S L(f1(n << 1, s, m, p, q)), R(f1(n << 1 | 1, m + 1, e, p, q));
	return seg[n] = { max(L.ls, L.ps + R.ls), max(R.rs, R.ps + L.rs), L.ps + R.ps, max({L.ms, R.ms, L.rs + R.ls}) };
}
S f2(r)
{
	if (s > q || e < p) return { M, M, 0, M };
	if (s >= p && e <= q) return seg[n];
	ll m((s + e) >> 1);
	S L(f2(n << 1, s, m, p, q)), R(f2(n << 1 | 1, m + 1, e, p, q));
	return { max(L.ls, L.ps + R.ls), max(R.rs, R.ps + L.rs), L.ps + R.ps, max({L.ms, R.ms, L.rs + R.ls}) };
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> q >> u >> v;
	for (ll i(1), j; i <= n; i++)
		cin >> j, f1(1, 1, n, i, j * u + v);
	for (ll i, j, k; q--;)
		if (cin >> i >> j >> k; i) f1(1, 1, n, j, k * u + v);
		else cout << f2(1, 1, n, j, k).ms - v << '\n';
}
