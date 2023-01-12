#include<bits/stdc++.h>
#define N 111
using namespace std;

int a[N][N][2], dp[N][N][N][2];
int t, n, m, l, g, i, j;

void in()
{
	cin >> n >> m >> l >> g;
	for (i = 1; i <= n; i++)
		for (j = 2; j <= m; cin >> a[i][j++][0]);
	for (i = 2; i <= n; i++)
		for (j = 1; j <= m; cin >> a[i][j++][1]);
}
void f()
{
	fill(&dp[0][0][0][0], &dp[0][0][0][0] + N * N * N * 2, 2e9);
	dp[1][1][0][0] = dp[1][1][0][1] = 0;
	int k = max(n, m);

	for (i = 2; i <= m; i++)
		dp[1][i][0][0] = dp[1][i - 1][0][0] + a[1][i][0];
	for (i = 2; i <= n; i++)
		dp[i][1][0][1] = dp[i - 1][1][0][1] + a[i][1][1];
	for(int l = 1; l <= k; l++)
		for(i = 1; i <= n; i++)
			for (j = 1; j <= m; j++)
			{
				dp[i][j][l][0] = min(dp[i][j - 1][l][0], dp[i][j - 1][l - 1][1]) + a[i][j][0];
				dp[i][j][l][1] = min(dp[i - 1][j][l][1], dp[i - 1][j][l - 1][0]) + a[i][j][1];
			}
	for (i = 0; i <= k; i++)
		if (min(dp[n][m][i][0], dp[n][m][i][1]) <= g)
		{
			cout << i + l * (n + m - 2) << '\n';
			return;
		}
	cout << -1 << '\n';
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while (t--)
	{
		in();
		f();
	}
}
