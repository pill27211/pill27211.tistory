#include<bits/stdc++.h>
using namespace std;

int a[101], b[101], dp[101][10001];
int n, t, i, j;

int main()
{
	cin >> n >> t;
	for (i = 1; i <= n; i++)
		cin >> a[i] >> b[i];
	for (i = 1; i <= n; i++)
		for (j = 1; j <= t; j++)
			dp[i][j] = j >= a[i] ? max(dp[i - 1][j], dp[i - 1][j - a[i]] + b[i]) : dp[i - 1][j];
	cout << dp[n][t];
}