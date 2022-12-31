#include<bits/stdc++.h>
using namespace std;

int n, m, i, j;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	while (cin >> n >> m, (n && m))
	{
		int r = 0, dp[1001][1001]{};
		for (i = 1; i <= n; i++)
			for (j = 1; j <= m; j++)
			{
				cin >> dp[i][j];
				if (dp[i][j])
					dp[i][j] = min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] }) + 1, r = max(r, dp[i][j]);
			}
		cout << r << '\n';
	}
}
