#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n, k, a[17], dp[17][1 << 16];

ll f(int p, int q)
{
	if (q == (1 << n) - 1) return 1;
	ll& t(dp[p][q]), i{};
	if (t == -1)
		for (t = 0; i < n; i++)
			if (!(q & (1 << i)) && (p == n || abs(a[i] - a[p]) > k))
				t += f(i, q | (1 << i));
	return t;
}
int main()
{
	memset(dp, -1, sizeof dp);
	cin >> n >> k;
	for (int i{}; i < n; cin >> a[i++]);
	cout << f(n, 0);
}
