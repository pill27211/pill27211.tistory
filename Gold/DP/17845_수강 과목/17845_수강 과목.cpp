#include<bits/stdc++.h>
using namespace std;

int a[1001], b[1001], dp[1001][10001];
int n, t, i, j;

int main()
{
	cin >> t >> n;
	for (i = 1; i <= n; i++)
		cin >> a[i] >> b[i];
	for (i = 1; i <= n; i++)
		for (j = 1; j <= t; j++)
			dp[i][j] = j >= b[i] ? max(dp[i - 1][j], dp[i - 1][j - b[i]] + a[i]) : dp[i - 1][j];
	cout << dp[n][t];
}