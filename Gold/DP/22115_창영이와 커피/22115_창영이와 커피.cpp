#include<bits/stdc++.h>
using namespace std;

int n, k, i, j, a[101], dp[101][100001];
int main()
{
	cin >> n >> k;
	for (i = 1; i <= n; cin >> a[i++]);
	for (i = 1; i <= k; dp[0][i++] = 2e9);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= k; j++)
			dp[i][j] = j >= a[i] ? min(dp[i - 1][j], dp[i - 1][j - a[i]] + 1) : dp[i - 1][j];
	cout << (dp[n][k] > n ? -1 : dp[n][k]);
}