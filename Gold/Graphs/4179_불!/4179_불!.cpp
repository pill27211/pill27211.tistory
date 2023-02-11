#include<bits/stdc++.h>
using namespace std;

int dy[]{ -1, 1, 0, 0 }, dx[]{ 0, 0, -1, 1 };
int r, c, i, j, t(2e9), V[1001][1001][2];
char M[1001][1001];
queue <pair<int, int>> Q[2];

void f(int o)
{
	while (Q[o].size())
	{
		auto [a, b](Q[o].front()); Q[o].pop();
		for (i = 0; i < 4; i++)
		{
			int y(a + dy[i]), x(b + dx[i]);
			if (y && x && y <= r && x <= c && M[y][x] ^ '#' && !V[y][x][o])
				V[y][x][o] = V[a][b][o] + 1, Q[o].push({ y, x });
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> r >> c;
	for (i = 1; i <= r; i++)
		for (j = 1; j <= c; j++)
		{
			cin >> M[i][j];
			if (M[i][j] == 'J') V[i][j][0] = 1, Q[0].push({ i, j });
			if (M[i][j] == 'F') V[i][j][1] = 1, Q[1].push({ i, j });
		}
	f(0); f(1);
	for (i = 1; i <= r; i++)
		for (j = 1; j <= c; j++)
			if (i == 1 || j == 1 || i == r || j == c)
				if (V[i][j][0] && (!V[i][j][1] || V[i][j][0] < V[i][j][1]))
					t = min(t, V[i][j][0]);
	t == 2e9 ? cout << "IMPOSSIBLE" : cout << t;
}
