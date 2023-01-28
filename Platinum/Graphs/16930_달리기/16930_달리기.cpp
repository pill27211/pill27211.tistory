#include<bits/stdc++.h>
using namespace std;

int dy[]{ -1, 1, 0, 0 }, dx[]{ 0, 0, -1, 1 };
int n, m, k, i, j, l, V[1001][1001];
char M[1001][1001];
int y, x, z, w;

void in()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; cin >> M[i][j++]);
	cin >> y >> x >> z >> w;
}
void f()
{
	queue <pair<int, int>> Q;
	Q.push({ y, x });
	V[y][x] = 1;
	while (Q.size())
	{
		auto [a, b](Q.front()); Q.pop();
		if (a == z && b == w)
			cout << V[a][b] - 1, exit(0);
		for (i = 0; i < 4; i++)
			for (j = l = 1; l <= k && j == l; l++)
			{
				int y(a + dy[i] * l), x(b + dx[i] * l);
				if (y > 0 && x > 0 && y <= n && x <= m && M[y][x] ^ '#')
				{
					if (V[y][x] && V[y][x] <= V[a][b]) break;
					if (!V[y][x]) Q.push({ y, x });
					j++, V[y][x] = V[a][b] + 1;
				}
			}
	}
}
int main()
{
	in();
	f();
	cout << -1;
}
