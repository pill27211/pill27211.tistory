#include <bits/stdc++.h>
using namespace std;

int a[1001], dp[1001][2];
int n, i, j, r = 1;
int main()
{
	cin >> n;
	for (i = 1; i <= n; cin >> a[i++]);
	for (i = 2; i <= n; i++)
		for (j = i - 1; j; j--)
			if (a[j] < a[i])
				dp[i][0] = max(dp[i][0], dp[j][0] + 1);
	for (i = n - 1; i; i--)
		for (j = i + 1; j <= n; j++)
			if (a[j] < a[i])
				dp[i][1] = max(dp[i][1], dp[j][1] + 1);
	for (i = 1; i <= n; i++)
		r = max(r, dp[i][0] + dp[i][1] + 1);
	cout << r;
}
