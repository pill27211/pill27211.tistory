#include<bits/stdc++.h>
#define ll long long
#define N 100001
using namespace std;

vector <pair<int, int>> Gr[N];
ll r(1e18), D[20][N], dp[20][1 << 20];
int n, m, i, s, e, P[20];

void in()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	fill(&D[0][0], &D[19][N], 1e18);
	memset(dp, -1, sizeof dp);
	cin >> n >> m;
	for (int p, q, w; m--;)
		cin >> p >> q >> w, Gr[p].emplace_back(q, w), Gr[q].emplace_back(p, w);
	cin >> s >> e >> m;
}
void f(int x, int y)
{
	priority_queue <pair<ll, int>> Q;
	Q.push({ 0, y }), D[x][y] = 0;
	while (Q.size())
	{
		auto [a, b](Q.top());
		a *= -1, Q.pop();
		if (D[x][b] >= a)
			for (auto& [p, q] : Gr[b])
				if (ll d = a + q; d < D[x][p])
					D[x][p] = d, Q.push({ -d, p });
	}
}
ll f2(int p, int q)
{
	if (q == (1 << m) - 1) return D[p][e];
	ll& t(dp[p][q]), i{};
	if (!~t)
		for (t = 1e18; i < m; i++)
			if (!(q & (1 << i)))
				t = min(t, f2(i, q | (1 << i)) + D[p][P[i]]);
	return t;
}
void sv()
{
	for (i = 0; i < m; i++)
		cin >> P[i], f(i, P[i]);
	for (i = 0; i < m; i++)
		r = min(r, f2(i, 1 << i) + D[i][s]);
	cout << (r < 1e18 ? r : -1);
}
int main()
{
	in();
	sv();
}
