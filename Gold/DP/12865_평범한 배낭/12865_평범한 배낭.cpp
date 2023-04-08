#include<bits/stdc++.h>
using namespace std;

int n, k, r, dp[100001];

int main()
{
	memset(dp, -1, sizeof dp); dp[0] = 0;
	for (cin >> n >> k; n--;)
	{
		int a, b; cin >> a >> b;
		for (int i(k - a); i >= 0; i--)
			if (!!~dp[i])
				dp[i + a] = max(dp[i + a], dp[i] + b);
	}
	for (n = 0; n <= k; r = max(r, dp[n++]));
	cout << r;
}
