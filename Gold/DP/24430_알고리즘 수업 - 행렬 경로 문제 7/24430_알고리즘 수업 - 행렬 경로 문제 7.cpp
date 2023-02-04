#include<bits/stdc++.h>
#define N 1001
using namespace std;

int n, k, i, j, a[N][N];
pair<int, int> dp[N][N];
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
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]), dp[i][j].first += a[i][j], dp[i][j].second += b[i][j];
	cout << dp[n][n].first << ' ' << dp[n][n].second;
}
