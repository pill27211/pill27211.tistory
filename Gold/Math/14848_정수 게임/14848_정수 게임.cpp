#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n, k, r, a[15];

int main()
{
	cin >> n >> k;
	for (ll i{}; i < k; cin >> a[i++]);
	for (ll i(1), j, l, t; i < (1 << k); i++, r += t * (n / l))
		for (t = -1, l = 1, j = 0; j < k; j++)
			if (i & (1 << j))
				t *= -1, l = lcm(l, a[j]);
	cout << n - r;
}
