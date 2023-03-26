#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n, p, q, r, a[18];

int main()
{
	cin >> n >> p >> q;
	for (ll i{}; i < n; cin >> a[i++]);
	for (ll i(1), j, l, c; i < (1 << n); i++)
	{
		for (c = -1, j = 0, l = 1; j < n; j++)
			if(i & (1 << j))
				c *= -1, l = lcm(l, a[j]);
		r += c * (q / l) - c * ((p - 1) / l);
	}
	cout << r;
}
