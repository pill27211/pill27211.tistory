#include<bits/stdc++.h>
using namespace std;

int dy[]{ -1, 1, 0, 0 }, dx[]{ 0, 0, -1, 1 };
queue <tuple <int, int, int, int>> Q;
char M[21][21], V[21][21][1 << 10];
int n, m, u, r, i, j;

void f()
{
	while (Q.size())
	{
		auto [a, b, c, d](Q.front()); Q.pop();
		if (c == (1 << u) - 1) r = min(r, d);
		for (i = 0; i < 4; i++)
		{
			int y(a + dy[i]), x(b + dx[i]);
			if (y && x && y <= n && x <= m && M[y][x] ^ 'x' && !V[y][x][c])
				V[y][x][c] = 1, Q.push({ y, x, M[y][x] > 64 && M[y][x] < 75 ? c | (1 << (M[y][x] - 65)) : c, d + 1 });
		}
	}
}
int main()
{
	while (cin >> m >> n, (m && n))
	{
		memset(V, 0, sizeof V);
		u = 0, r = 2e9;
		for (i = 1; i <= n; i++)
			for (j = 1; j <= m; j++)
			{
				cin >> M[i][j];
				if (M[i][j] == '*') M[i][j] = 65 + u++;
				if (M[i][j] == 'o') V[i][j][0] = 1, Q.push({ i, j, 0, 0 });
			}
		f(), cout << (r == 2e9 ? -1 : r) << '\n';
	}
}
