#include <bits/stdc++.h>
using namespace std;

int n, a[501], b[501], dp[501][501];

int f(int p, int q)
{
	if (p + 1 == q)
		return dp[p][q] = a[p] * b[p] * b[q];
	if (p == q || dp[p][q])
		return dp[p][q];
	dp[p][q] = INT_MAX;
	for (int i = p; i < q; i++)
		dp[p][q] = min(dp[p][q], f(p, i) + f(i + 1, q) + a[p] * b[i] * b[q]);
	return dp[p][q];
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &a[i], &b[i]);
	cout << f(1, n);
}
