#include<bits/stdc++.h>
using namespace std;
using ll = long long;

priority_queue <ll> Q;
unordered_set <ll> S;
ll k, n, m, a[101];

int main()
{
	cin >> k >> n; Q.push(-1);
	for (ll i{}; i < k; cin >> a[i++]);
	while (n--)
	{
		ll t(-Q.top()); Q.pop();
		for (ll i{}; i < k; i++)
			if (ll x(t * a[i]); !S.count(x) && (!(Q.size() > n && x >= m)))
			{
				Q.push(-x), S.insert(x);
				m = max(m, x);
			}
	}
	cout << -Q.top();
}
