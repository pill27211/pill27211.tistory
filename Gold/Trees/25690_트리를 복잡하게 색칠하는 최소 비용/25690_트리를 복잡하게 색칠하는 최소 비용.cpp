#include<bits/stdc++.h>
#define ll long long
#define N 100001
using namespace std;

vector <int> Gr[N];
int n, a[N], b[N];
ll dp[N][2];

ll f(int p, int q, int o)
{
	ll& t(dp[p][q]), s(0);
	if (t ^ -1) return t;
	t = 1e18;
	for (int i : Gr[p])
		if (i ^ o)
		{
			ll k(1e18);
			k = min(k, f(i, 0, p) + a[i]);
			if (!q) k = min(k, f(i, 1, p) + b[i]);
			s += k;
		}
	return t = s;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(dp, -1, sizeof dp);
	cin >> n;
	for (int o(1), i, j; o < n; o++)
		cin >> i >> j, Gr[i].push_back(j), Gr[j].push_back(i);
	for (int i{}; i < n; i++)
		cin >> a[i] >> b[i];
	cout << min(f(0, 0, 0) + a[0], f(0, 1, 0) + b[0]);
}
