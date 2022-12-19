#include<bits/stdc++.h>
#define r int n, int s, int e, int p, int q
#define ll long long
#define rs { min(L.x, R.x), max(L.y, R.y), max({ L.z, R.z, (ll)R.y - L.x }) }
using namespace std;

struct S { int x, y; ll z; } seg[1 << 18];
int n, q, o, i, j;

S f1(r)
{
	if (s > p || e < p)
		return seg[n];
	if (s == e)
		return seg[n] = { q, q, 0 };
	int m = (s + e) >> 1;
	S L = f1(n << 1, s, m, p, q);
	S R = f1(n << 1 | 1, m + 1, e, p, q);
	return seg[n] = rs;
}
S f2(r)
{
	if (s > q || e < p)
		return { (int)2e9 + 1, -(int)2e9 - 1, 0 };
	if (s >= p && e <= q)
		return seg[n];
	int m = (s + e) >> 1;
	S L = f2(n << 1, s, m, p, q);
	S R = f2(n << 1 | 1, m + 1, e, p, q);
	return rs;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (i = 1; i <= n; i++)
		cin >> j, f1(1, 1, n, i, j);
	cin >> q;
	while (q--)
	{
		cin >> o >> i >> j;
		if (o & 1)
			f1(1, 1, n, i, j);
		else
			cout << f2(1, 1, n, i, j).z << '\n';
	}
}