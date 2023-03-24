#include<bits/stdc++.h>
#define ll long long
using namespace std;

unordered_map <ll, ll> M;
ll n, p, q, a, b;

ll f(ll x)
{
	if (x < 1) return 1;
	if (!M.count(x))
		M[x] = f(x / p - a) + f(x / q - b);
	return M[x];
}
int main()
{
	cin >> n >> p >> q >> a >> b;
	cout << f(n);
}
