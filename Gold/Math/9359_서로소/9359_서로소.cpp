#include<bits/stdc++.h>
#define T vector <ll>
#define ll long long
using namespace std;

ll t, a, b, n, o;

void f(T& V)
{
	for (ll i(2); i <= sqrt(n); i++)
		if (!(n % i))
			if (V.push_back(i); i ^ (n / i))
				V.push_back(n / i);
	sort(V.begin(), V.end());
}
void g(T& V, T& R)
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
void sv(T& R, ll r = 0)
{
	for (ll i(1), j, l, c; i < (1 << R.size()); r += c * (b / l) - c * ((a - 1) / l), i++)
		for (c = -1, j = 0, l = 1; j < R.size(); j++)
			if (i & (1 << j))
				if (c *= -1, l = lcm(l, R[j]); l > b)
					c = 0, j = 1e9;
	printf("Case #%lld: %lld\n", ++o, b - a + 1 - (n < 2 ? 0 : r));
}
int main()
{
	for (cin >> t; o < t;)
	{
		cin >> a >> b >> n;
		T V(1, n), R;
		f(V);
		g(V, R);
		sv(R);
	}
}
