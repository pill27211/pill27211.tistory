#include<bits/stdc++.h>
using namespace std;

int dy[]{ -1, 1, 0, 0 }, dx[]{ 0, 0, -1, 1 };
queue <tuple <int, int, int, int>> Q;
char M[51][51], V[51][51][1 << 5];
int n, m, u, i, j;

void f()
{
	while (Q.size())
	{
		auto [a, b, c, d](Q.front()); Q.pop();
		if (c == (1 << u) - 1 && M[a][b] == 'E') cout << d, exit(0);
		for (i = 0; i < 4; i++)
		{
			int y(a + dy[i]), x(b + dx[i]);
			if (y && x && y <= n && x <= m && M[y][x] ^ '#' && !V[y][x][c])
				V[y][x][c] = 1, Q.push({ y, x, M[y][x] > 96 ? c | (1 << (M[y][x] - 65)) : c, d + 1 });
		}
	}
}
int main()
{
	cin >> m >> n;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
		{
			cin >> M[i][j];
			if (M[i][j] == 'X') M[i][j] = 97 + u++;
			if (M[i][j] == 'S') V[i][j][0] = 1, Q.push({ i, j, 0, 0 });
		}
	f();
}
