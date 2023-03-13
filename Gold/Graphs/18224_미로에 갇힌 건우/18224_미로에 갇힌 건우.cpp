#include<bits/stdc++.h>
using namespace std;

int dy[]{ -1, 1, 0, 0 }, dx[]{ 0, 0, -1, 1 };
bool M[501][501], V[501][501][11][2];
int n, m, i, j, W[501][501][4];

bool f(int y, int x) { return y > 0 && x > 0 && y <= n && x <= n; }
void in()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; cin >> M[i][j++]);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			if (M[i][j])
				for (int l{}; l < 4; l++)
				{
					int y(i + dy[l]), x(j + dx[l]), c(1);
					while (y && x && y <= n && x <= n && M[y][x])
						c++, y += dy[l], x += dx[l];
					W[i][j][l] = c;
				}
}
void sv()
{
	queue <tuple<int, int, int, int, int>> Q;
	Q.push({ 1, 1, 0, 0, 0 });
	while (Q.size())
	{
		auto [a, b, c, d, e](Q.front()); Q.pop();
		if (a == n && b == n)
			cout << 1 + e / (m << 1) << ' ' << (d ? "moon" : "sun"), exit(0);
		for (i = 0; i < 4; i++)
		{
			int y(a + dy[i]), x(b + dx[i]);
			if (f(y, x))
			{
				if (!M[y][x] && !V[y][x][(c + 1) % m][d ^ (c + 1 == m)])
					V[y][x][(c + 1) % m][d ^ (c + 1 == m)] = 1, Q.push({ y, x, (c + 1) % m, d ^ (c + 1 == m), e + 1 });
				if (d && M[y][x])
				{
					int _y(y + dy[i] * W[y][x][i]), _x(x + dx[i] * W[y][x][i]);
					if (f(_y, _x) && !M[_y][_x] && !V[_y][_x][(c + 1) % m][d ^ (c + 1 == m)])
						V[_y][_x][(c + 1) % m][d ^ (c + 1 == m)] = 1, Q.push({ _y, _x, (c + 1) % m, d ^ (c + 1 == m), e + 1 });
				}
			}
		}
	}
	cout << -1;
}
int main()
{
	in();
	sv();
}
