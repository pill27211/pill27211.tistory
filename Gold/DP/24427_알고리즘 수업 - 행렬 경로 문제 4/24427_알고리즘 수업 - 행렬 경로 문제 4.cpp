#include<bits/stdc++.h>
#define R for (i = 1; i <= n; i++) for (j = 1; j <= n; j++)
#define N 1001
using namespace std;

int n, k, i, j, a[N][N], dp[N][N];
bool b[N][N];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	R
		cin >> a[i][j];
	cin >> k;
	while (k--)
		cin >> i >> j, b[i][j] = 1;
	R
		dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
	R
		dp[i][j] = b[i][j] ? dp[i][j] : 0;
	R
		if (dp[i - 1][j] || dp[i][j - 1])
			dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i][j - 1]) + a[i][j]);
	cout << dp[n][n];
}
