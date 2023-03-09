#include<bits/stdc++.h>
using namespace std;

int n, m, i, a[101], c[101], dp[10001];

int main()
{
	memset(dp, -1, sizeof dp);
	cin >> n >> m; dp[0] = 0;
	for (i = 1; i <= n; cin >> a[i++]);
	for (i = 1; i <= n; cin >> c[i++]);
	for (i = 1; i <= n; i++)
		for (int j = 10000; j >= c[i]; j--)
			if (!!~dp[j - c[i]])
				dp[j] = max(dp[j], dp[j - c[i]] + a[i]);	
	for (i = 0;; i++)
		if (dp[i] >= m)
			cout << i, exit(0);
}
