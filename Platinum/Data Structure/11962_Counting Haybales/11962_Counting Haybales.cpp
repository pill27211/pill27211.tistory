#include<bits/stdc++.h>
#define r int n, int s, int e
#define ll long long
using namespace std;

struct S { ll x, y; }t, seg[1 << 19];
ll n, q, lz[1 << 19];
char c;

void f0(r)
{
	if (lz[n])
	{
		seg[n].x += lz[n] * (e - s + 1);
		seg[n].y += lz[n];
		if (s ^ e)
			lz[n << 1] += lz[n], lz[n << 1 | 1] += lz[n];
		lz[n] = 0;
	}
}
S f1(r, int p, int q, int k)
{
	f0(n, s, e);
	if (s > q || e < p) return seg[n];
	if (s >= p && e <= q)
	{
		lz[n] += k;
		f0(n, s, e);
		return seg[n];
	}
	int m((s + e) >> 1);
	S L(f1(n << 1, s, m, p, q, k)), R(f1(n << 1 | 1, m + 1, e, p, q, k));
	return seg[n] = { L.x + R.x, min(L.y, R.y) };
}
S f2(r, int p, int q)
{
	f0(n, s, e);
	if (s > q || e < p) return { 0, (ll)1e18 };
	if (s >= p && e <= q) return seg[n];
	int m((s + e) >> 1);
	S L(f2(n << 1, s, m, p, q)), R(f2(n << 1 | 1, m + 1, e, p, q));
	return { L.x + R.x, min(L.y, R.y) };
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> q;
	for (int i(1), j; i <= n; i++)
		cin >> j, f1(1, 1, n, i, i, j);
	for (int i, j, k; q--;)
	{
		cin >> c >> i >> j;
		if (c == 'P')
			cin >> k, f1(1, 1, n, i, j, k);
		else
			t = f2(1, 1, n, i, j), cout << (c == 'S' ? t.x : t.y) << '\n';
	}
}
