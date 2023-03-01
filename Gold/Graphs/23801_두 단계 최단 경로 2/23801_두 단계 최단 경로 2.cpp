#include<bits/stdc++.h>
#define ll long long
#define N 100001
using namespace std;

vector <pair<int, int>> Gr[N];
priority_queue <pair<ll, int>> Q;
ll r(1e18), D[2][N];
int n, m, i, j, w;

void in()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	fill(&D[0][0], &D[1][N], 1e18);
	cin >> n >> m;
	while (m--)
		cin >> i >> j >> w, Gr[i].emplace_back(j, w), Gr[j].emplace_back(i, w);
	cin >> i >> j;
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
int main()
{
	in();
	f(i, 0), f(j, 1);
	cin >> i;
	while (i--)
	{
		cin >> j;
		if (D[0][j] < 1e18 && D[1][j] < 1e18) r = min(r, D[0][j] + D[1][j]);
	}
	cout << (r == 1e18 ? -1 : r);
}
