#include <bits/stdc++.h>
#define ll long long
#define N 1001
using namespace std;

ll n, u, a[N], dp[N][N][2];

ll f(ll p, ll q, ll w)
{
	if (!~p || q > n) return 1e15;
	if (!p && q == n) return 0;
	ll& t(dp[p][q][w]), k(w ? q : p), l(n - q + p);
	if (!~t)
		t = 1e15, t = min(f(p, q + 1, 1) + l * (a[q + 1] - a[k]), f(p - 1, q, 0) + l * (a[k] - a[p - 1]));
	return t;
}
int main()
{
	memset(dp, -1, sizeof dp);
	cin >> n >> u; a[0] = u;
	for (int i = 1; i <= n; scanf("%lld", &a[i++]));
	sort(a, a + n + 1); u = lower_bound(a, a + n, u) - a;
	cout << f(u, u, 0);
}
