#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector <ll> V;
ll a, b, l;

int main()
{
	cin >> a >> b >> l; a = lcm(a, b);
	for (ll i(1); i <= sqrt(l); i++)
		if (!(l % i))
			V.push_back(i), V.push_back(l / i);
	sort(V.begin(), V.end());
	for (ll i : V)
		if (lcm(i, a) == l)
			cout << i, exit(0);
	cout << -1;
}
