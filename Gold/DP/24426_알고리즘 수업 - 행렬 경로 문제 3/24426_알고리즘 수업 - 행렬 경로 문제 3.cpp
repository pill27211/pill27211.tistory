#include<bits/stdc++.h>
#define N 1001
using namespace std;

int n, y, x, i, j, a[N][N], dp[N][N];

int main()
{
	cin >> n;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; scanf("%d", &a[i][j++]));
	cin >> y >> x;
	for (i = 1; i <= y; i++)
		for (j = 1; j <= x; j++)
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
	for (i = y; i <= n; i++)
		for (j = x; j <= n; j++)
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
	cout << dp[n][n] << ' ';
	memset(dp, 0, sizeof dp);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			if (i ^ y || j ^ x)
			{
				if ((i == y && i == 1 && j >= x) || (j == x && j == 1 && i >= y)) continue;
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
			}
	cout << dp[n][n];
}
