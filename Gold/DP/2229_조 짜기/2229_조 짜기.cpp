#include<bits/stdc++.h>
using namespace std;

int n, i, j, a[1001], dp[1001];
int main()
{
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		int m = 2e9, M = -1;
		for (cin >> a[i], j = i; j; j--)
			M = max(M, a[j]), m = min(m, a[j]), dp[i] = max(dp[i], dp[j - 1] + M - m);
	}
	cout << dp[n];
}
