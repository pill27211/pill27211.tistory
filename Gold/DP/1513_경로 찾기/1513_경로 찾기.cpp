#include <bits/stdc++.h>
using namespace std;

int a[51][51], dp[51][51][51][51];
int n, m, c, i, j;

int f(int p, int q, int k, int o)
{
	if (p > n || q > m)
		return 0;
	if (p == n && q == m)
		return (!a[p][q] && !k) || (k == 1 && a[p][q] > o);
	auto& i(dp[p][q][k][o]);
	if (i ^ -1)
		return i;
	i = 0;
	if (a[p][q] > o && k > 0)
		i = f(p + 1, q, k - 1, a[p][q]) + f(p, q + 1, k - 1, a[p][q]);
	else if (!a[p][q])
		i = f(p + 1, q, k, o) + f(p, q + 1, k, o);
	return i % 1000007;
}
int main()
{
	memset(dp, -1, sizeof dp);
	cin >> n >> m >> c;
	for (int o = 1; o <= c; o++)
		cin >> i >> j, a[i][j] = o;
	for (i = 0; i <= c; cout << f(1, 1, i++, 0) << ' ');
}
