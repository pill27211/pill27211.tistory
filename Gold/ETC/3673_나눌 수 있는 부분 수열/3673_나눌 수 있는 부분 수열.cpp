#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll t, n, m, i, a[50001];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while(t--)
	{
		ll r{}, c[1000001]{};
		cin >> m >> n;
		for (i = 1; i <= n; c[a[i++]]++)
			cin >> a[i], a[i] = (a[i] + a[i - 1]) % m;
		for (i = 0; i < m; i++)
			r += c[i] * (c[i] - 1) / 2;
		cout << r + c[0] << '\n';
	}
}
