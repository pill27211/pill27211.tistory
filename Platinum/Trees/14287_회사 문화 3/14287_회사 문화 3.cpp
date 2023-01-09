#include<bits/stdc++.h>
#define r int n, int s, int e, int p, int q
#define N 100001
using namespace std;

vector <int> Gr[N];
int in[N], out[N], seg[1 << 18];
int n, q, o, i, j;

void f1(int p)
{
	in[p] = ++o;
	for (int a : Gr[p])
		f1(a);
	out[p] = o;
}
int f2(r)
{
	if (s > p || e < p)
		return seg[n];
	if (s == e)
		return seg[n] += q;
	int m = (s + e) >> 1;
	return seg[n] = f2(n << 1, s, m, p, q) + f2(n << 1 | 1, m + 1, e, p, q);
}
int f3(r)
{
	if (s > q || e < p)
		return 0;
	if (s >= p && e <= q)
		return seg[n];
	int m = (s + e) >> 1;
	return f3(n << 1, s, m, p, q) + f3(n << 1 | 1, m + 1, e, p, q);
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> q >> i;
	for (i = 2; i <= n; i++)
		cin >> j, Gr[j].emplace_back(i);
	f1(1);
	while (q--)
	{
		cin >> o >> i;
		if (o & 1)
			cin >> j, f2(1, 1, n, in[i], j);
		else
			cout << f3(1, 1, n, in[i], out[i]) << '\n';
	}
}
