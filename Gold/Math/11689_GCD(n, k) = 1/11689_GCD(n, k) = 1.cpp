#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector <ll> V, R;
ll n, r;

void f()
{
	V.push_back(n);
	for (ll i(2); i <= sqrt(n); i++)
		if (!(n % i))
			if (V.push_back(i); i ^ (n / i))
				V.push_back(n / i);
	sort(V.begin(), V.end());
}
void g()
{
	for (ll i{}; i < V.size(); i++)
		if (V[i])
		{
			for (ll j(i + 1); j < V.size(); j++)
				if (V[j] && !(V[j] % V[i]))
					V[j] = 0;
			R.push_back(V[i]);
		}
}
void sv()
{
	for (ll i(1), j, l, c; i < (1 << R.size()); r += c * (n / l), i++)
		for (c = -1, j = 0, l = 1; j < R.size(); j++)
			if (i & (1 << j))
				if (c *= -1, l = lcm(l, R[j]); l > n)
					c = 0, j = 1e9;
	cout << max(1LL, n - r) << '\n';
}
int main()
{
	cin >> n;
	f();
	g();
	sv();
}
