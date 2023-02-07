#include<bits/stdc++.h>
#define N 100001
using namespace std;

int n, i, p, q, c[N], seg[N];

void f1(int p, int q)
{
	while (p <= N - 1)
		seg[p] += q, p += p & -p;
}
int f2(int p)
{
	int r{};
	while (p)
		r += seg[p], p -= p & -p;
	return r;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n; q = n;
	for (i = 1; i <= n; i++)
		cin >> p, c[p] = i, f1(p, 1);
	for (p = i = 1; i <= n; i++)
		i & 1 ? (cout << f2(c[p] - 1) << '\n', f1(c[p++], -1)) : (cout << f2(N - 1) - f2(c[q]) << '\n', f1(c[q--], -1));
}
