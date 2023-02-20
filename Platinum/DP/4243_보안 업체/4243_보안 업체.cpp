#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll t, n, u, a[101], dp[101][101][2];

ll f(ll p, ll q, ll w)
{
	if (!p || q > n) return 2e18;
	if (p == 1 && q == n) return 0;
	ll& t(dp[p][q][w]), k(w ? q : p), l(n - q + p - 1);
	if (t == -1)
		t = 2e18, t = min(f(p, q + 1, 1) + l * (a[q + 1] - a[k]), f(p - 1, q, 0) + l * (a[k] - a[p - 1]));
	return t;
}
int main()
{
	cin >> t;
	while (t--)
	{
		memset(dp, -1, sizeof dp);
		cin >> n >> u;
		for (int i = 2; i <= n; i++)
			scanf("%lld", &a[i]), a[i] += a[i - 1];
		cout << f(u, u, 0) << '\n';
	}
}
