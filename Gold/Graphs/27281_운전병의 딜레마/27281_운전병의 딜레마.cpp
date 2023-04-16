#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector <tuple<int, int, int>> Gr[50001];
int n, m, t, r(-1);

ll f()
{
	priority_queue <pair<ll, int>> Q;
	vector <ll> D(50001, 1e18);
	for (Q.push({ D[1] = 0, 1 }); Q.size();)
	{
		auto [x, y] = Q.top(); Q.pop();
		if (D[y] >= -x)
			for (auto& [a, b, w] : Gr[y])
				if (ll k = b - x + max(w - m, 0); k < D[a] && k <= t)
					D[a] = k, Q.push({ -k, a });
	}
	return D[n];
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> t;
	for (int u, v, x, y; m--;)
		cin >> u >> v >> x >> y, Gr[u].emplace_back(v, x, y), Gr[v].emplace_back(u, x, y);
	for (int p{}, q(1e9); p <= q; f() <= t ? r = m, q = m - 1 : p = m + 1) m = p + q >> 1;
	cout << r;
}
