#include<bits/stdc++.h>
using namespace std;

int n, i, r, a[100001], dp[100001][2];
int main()
{
	cin >> n; dp[0][0] = dp[0][1] = r = -2e9;
	for (i = 1; i <= n; scanf("%d", &a[i++]));
	for (i = 1; i <= n; i++)
	{
		dp[i][0] = max(dp[i - 1][0] + a[i], a[i]);
		dp[i][1] = max(dp[i - 1][1] + a[i], dp[i - 1][0]);
		r = max({ r, dp[i][0], dp[i][1] });
	}
	cout << r;
}