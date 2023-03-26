#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n, p, r, a[20];

int main()
{
	cin >> p >> n;
	for (ll i{}; i < n; cin >> a[i++]);
	for (ll i(1), j, l, c; i < (1 << n); i++, r += c * (p / l))
		for (c = -1, j = 0, l = 1; j < n; j++)
			if (i & (1 << j))
			{
				c *= -1, l = lcm(l, a[j]);
				if (l > p)
					c = 0, j = n;
			}
	cout << r;
}
