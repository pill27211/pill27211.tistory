#include<bits/stdc++.h>
using namespace std;

int n, i, r, a[100001][2], dp[100001][2];
int main()
{
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i][0]);
		a[i][0] = a[i][0] & 1 ? 1 : -1;
		a[i][1] = a[i][0] == 1 ? -1 : 1;
	}
	for (i = 1; i <= n; i++)
	{
		dp[i][0] = max(a[i][0], dp[i - 1][0] + a[i][0]);
		dp[i][1] = max(a[i][1], dp[i - 1][1] + a[i][1]);
		r = max({ r, dp[i][0], dp[i][1] });
	}
	cout << r;
}
