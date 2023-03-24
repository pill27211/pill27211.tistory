#include<bits/stdc++.h>
#define ll long long
using namespace std;

unordered_map <ll, ll> M{ {0, 1} };
ll n, p, q;

ll f(ll x)
{
	if (!M.count(x))
		M[x] = f(x / p) + f(x / q);
	return M[x];
}
int main()
{
	cin >> n >> p >> q;
	cout << f(n);
}
