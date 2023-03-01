#include<bits/stdc++.h>
#define N 100001
using namespace std;

priority_queue <pair<int, int>> Q;
vector <pair<int, int>> Gr[N];
int n, m, i, j, w, D[3][N];
int a, b, c;

void in()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	fill(&D[0][0], &D[2][N], 1e9);
	cin >> n >> a >> b >> c >> m;
	while (m--)
		cin >> i >> j >> w, Gr[i].emplace_back(j, w), Gr[j].emplace_back(i, w);
}
void f(int p, int q)
{
	Q.push({ 0, p }), D[q][p] = 0;
	while (Q.size())
	{
		auto [a, b](Q.top());
		Q.pop(); a *= -1;
		if(a <= D[q][b])
			for (auto& [i, j] : Gr[b])
			{
				int d(a + j);
				if (d < D[q][i])
					D[q][i] = d, Q.push({ -d, i });
			}
	}
}
int main()
{
	in();
	f(a, 0), f(b, 1), f(c, 2);
	for (i = 1, m = 0; i <= n; i++)
		if (a ^ i && b ^ i && c ^ i)
		{
			j = min({ D[0][i], D[1][i], D[2][i] });
			if (m < j)
				m = j, w = i;
		}
	cout << w;
}
