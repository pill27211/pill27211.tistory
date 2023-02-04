#include<bits/stdc++.h>
#define f(x, y) dp[i][j][x] = a[i][j] + max(dp[i - 1][j][x - y], dp[i][j - 1][x - y])
#define N 1001
using namespace std;

int n, k, i, j, a[N][N], dp[N][N][4];
bool b[N][N];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; cin >> a[i][j++]);
	cin >> k;
	while (k--)
		cin >> i >> j, b[i][j] = 1;
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			if (b[i][j])
			{
				for (k = 0; k < 3; k++)
					if (dp[i - 1][j][k] || dp[i][j - 1][k])
						f(k + 1, 1);
			}
			else
			{
				dp[i][j][0] = max(dp[i - 1][j][0], dp[i][j - 1][0]) + a[i][j];
				for (k = 1; k <= 3; k++)
					if (dp[i - 1][j][k] || dp[i][j - 1][k])
						f(k, 0);
			}
	cout << (dp[n][n][3] ? dp[n][n][3] : -1);
}
