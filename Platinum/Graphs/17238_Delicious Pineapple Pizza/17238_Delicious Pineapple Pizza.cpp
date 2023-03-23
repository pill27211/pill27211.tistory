#include<bits/stdc++.h>
#define ll long long
#define N 201
using namespace std;

vector <ll> Gr[N];
ll n, i, a[N], D[N], V[N];
ll p, q(1e10), r;

ll f(ll p)
{
	for (ll i : Gr[p])
		if (!V[i])
			if (V[i] = 1, !D[i] || f(D[i]))
				return D[i] = p, 1;
	return 0;
}
int main()
{
	cin >> n;
	for (i = 1; i <= n * 2; cin >> a[i++]);
	while (p <= q)
	{
		ll t{}, m((p + q) >> 1);
		for (i = 1; i <= n; i++)
			for (ll j(n + 1); j <= n * 2; j++)
				if ((a[i] ^ a[j]) >= m)
					Gr[i].push_back(j);

		for (i = 1; i <= n; t += f(i++))
			memset(V, 0, sizeof V);
		for (i = 1; i < N; i++)
			Gr[i].clear(), D[i] = 0;

		t == n ? r = m, p = m + 1 : q = m - 1;
	}
	cout << r;
}
