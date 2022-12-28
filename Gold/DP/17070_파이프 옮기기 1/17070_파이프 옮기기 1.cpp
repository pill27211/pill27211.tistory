#include<bits/stdc++.h>
using namespace std;

int n, i, j, w, M[22][22], dp[22][22][3];

int main()
{
	cin >> n; dp[1][2][0] = 1;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			cin >> M[i][j];
	for (i = 1; i <= n; i++)
		for (j = 3; j <= n; j++)
			if (!M[i][j])
			{
				dp[i][j][0] += dp[i][j - 1][0] + dp[i][j - 1][2];
				dp[i][j][1] += dp[i - 1][j][1] + dp[i - 1][j][2];
				if (!M[i - 1][j] && !M[i][j - 1])
					dp[i][j][2] += dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
			}
	cout << dp[n][n][0] + dp[n][n][1] + dp[n][n][2];
}