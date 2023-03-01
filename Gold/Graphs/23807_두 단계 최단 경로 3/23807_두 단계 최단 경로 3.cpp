#include<bits/stdc++.h>
#define ll long long
#define N 100001
using namespace std;

vector <pair<int, int>> Gr[N];
priority_queue <pair<ll, int>> Q;
ll r(1e18), D[101][N];
int n, m, i, j, w, P[101];
int a, b;

void in()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	fill(&D[0][0], &D[100][N], 1e18);
	cin >> n >> m;
	while (m--)
		cin >> i >> j >> w, Gr[i].emplace_back(j, w), Gr[j].emplace_back(i, w);
	cin >> a >> b >> m;
}
void f(int p, int q)
{
	Q.push({ 0, p }), D[q][p] = 0;
	while (Q.size())
	{
		auto [a, b](Q.top());
		Q.pop(); a *= -1;
		if (a <= D[q][b])
			for (auto& [i, j] : Gr[b])
			{
				ll d(a + j);
				if (d < D[q][i])
					D[q][i] = d, Q.push({ -d, i });
			}
	}
}
void sv()
{
	for (i = 1; i <= m; i++)
		cin >> P[i], f(P[i], i);
	for (i = 1; i <= m; i++)
		for (j = 1; j <= m; j++)
			if (i ^ j)
				for (w = 1; w <= m; w++)
					if (i ^ w && j ^ w)
						r = min(r, D[i][a] + D[i][P[j]] + D[j][P[w]] + D[w][b]);
	cout << (r == 1e18 ? -1 : r);
}
int main()
{
	in();
	sv();
}
