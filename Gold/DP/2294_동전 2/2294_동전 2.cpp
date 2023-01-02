#include<bits/stdc++.h>
using namespace std;

int n, k, i, j, a[101], dp[10001];
int main()
{
	fill(dp, dp + 10001, 2e9);
	cin >> n >> k; dp[0] = 1;
	for (; i < n; cin >> a[i++]);
	for (i = 0; i < n; i++)
		for (j = a[i]; j < 10001; j++)
			dp[j] = min(dp[j], dp[j - a[i]] + 1);
	cout << (dp[k] == 2e9 ? -1 : dp[k] - 1);
}
