#include<bits/stdc++.h>
using namespace std;

int t, n, a[501], dp[501][501];

int f(int p, int q)
{
	if (p ^ q && !dp[p][q])
	{
		dp[p][q] = 2e9;
		for (int i = p; i < q; i++)
			dp[p][q] = min(dp[p][q], f(p, i) + f(i + 1, q) + a[q] - a[p - 1]);
	}
	return dp[p][q];
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i], a[i] += a[i - 1];
		cout << f(1, n) << '\n';
		memset(dp, 0, sizeof dp);
	}
}
