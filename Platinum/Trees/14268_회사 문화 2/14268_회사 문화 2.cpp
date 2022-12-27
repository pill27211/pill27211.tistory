#include<bits/stdc++.h>
#define r int n, int s, int e
#define N 100001
using namespace std;

vector <int> Gr[N];
int seg[1 << 18], lz[1 << 18];
int in[N], out[N];
int n, q, o, i, j;

void f1(int p)
{
	in[p] = ++o;
	for (int a : Gr[p])
		f1(a);
	out[p] = o;
}
void f2(r)
{
	if (lz[n])
	{
		seg[n] += lz[n] * (e - s + 1);
		if (s ^ e)
			lz[n << 1] += lz[n], lz[n << 1 | 1] += lz[n];
		lz[n] = 0;
	}
}
int f3(r, int p, int q, int k)
{
	f2(n, s, e);
	if (s > q || e < p)
		return seg[n];
	if (s >= p && e <= q)
	{
		seg[n] += k * (e - s + 1);
		if (s ^ e)
			lz[n << 1] += k, lz[n << 1 | 1] += k;
		return seg[n];
	}
	int m = (s + e) >> 1;
	return seg[n] = f3(n << 1, s, m, p, q, k) + f3(n << 1 | 1, m + 1, e, p, q, k);
}
int f4(r, int p)
{
	f2(n, s, e);
	if (s > p || e < p)
		return 0;
	if (s == e)
		return seg[n];
	int m = (s + e) >> 1;
	return f4(n << 1, s, m, p) + f4(n << 1 | 1, m + 1, e, p);
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
			cin >> j, f3(1, 1, n, in[i], out[i], j);
		else
			cout << f4(1, 1, n, in[i]) << '\n';
	}
}
