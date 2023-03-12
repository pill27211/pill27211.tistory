#include<bits/stdc++.h>
using namespace std;

int dy[]{ -1, 1, 0, 0 }, dx[]{ 0, 0, -1, 1 };
queue <tuple<int, int, int, int, int>> Q;
int n, m, k, r(1e9), M[1001][1001];
bool V[1001][1001][10][2];

int main()
{
	cin >> n >> m >> k;
	for (int i(1); i <= n; i++)
		for (int j(1); j <= m; scanf("%1d", &M[i][j++]));
	Q.push({ 1, 1, 0, 1, 1 });
	V[1][1][0][1] = 1;
	while (Q.size())
	{
		auto [a, b, c, d, e](Q.front()); Q.pop();
		if (a == n && b == m) r = min(r, e);
		if (!V[a][b][c][d ^ 1])
			V[a][b][c][d ^ 1] = 1, Q.push({ a, b, c, d ^ 1, e + 1 });
		for (int i{}; i < 4; i++)
		{
			int y(a + dy[i]), x(b + dx[i]);
			if (y && x && y <= n && x <= m)
			{
				if (M[y][x] && d && c < k && !V[y][x][c + 1][0])
					V[y][x][c + 1][0] = 1, Q.push({ y, x, c + 1, 0, e + 1 });
				if (!M[y][x] && !V[y][x][c][d ^ 1])
					V[y][x][c][d ^ 1] = 1, Q.push({ y, x, c, d ^ 1, e + 1 });
			}
		}
	}
	cout << (r == 1e9 ? -1 : r);
}
