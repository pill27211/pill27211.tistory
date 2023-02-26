#include<bits/stdc++.h>
#define ll long long
#define N 1003
using namespace std;

int n, m, i, j, t, a[N], b[N];
ll p[N][N], dp[11][N];

int main()
{
	cin >> n >> m;
	for (i = 1; i <= n; i++)
		cin >> a[i] >> b[i], p[i][i] = b[i];
	for (i = 1; i <= n; i++)
		for (t = a[i], j = i + 1; j <= n; j++)
			t <= a[j] ? (t < a[j] ? p[i][j] = b[j], t = a[j] : p[i][j] = p[i][j - 1] + b[j]) : p[i][j] = p[i][j - 1];
	for (i = 1; i <= n; i++)
		dp[1][i] = p[1][i];
	for (i = 2; i <= m; i++)
		for (j = 1; j <= n; j++)
			for (t = j - 1; t >= i - 1; t--)
				dp[i][j] = max(dp[i][j], dp[i - 1][t] + p[t + 1][j]);
	cout << dp[m][n];
}
