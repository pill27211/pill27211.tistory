#include<bits/stdc++.h>
using namespace std;

int dy[]{ -1, 1, 0, 0 }, dx[]{ 0, 0, -1, 1 };
int n, m, k, r(1e9), i, j, M[201][201];
bool C[6][6], V[201][201][31][3];

void in()
{
	cin >> n >> m >> k;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; scanf("%d", &M[i][j++]));
	for (i = 1; i < 6; i++)
		for (j = 1; j < 6; cin >> C[i][j++]);
}
void sv()
{
	queue <tuple<int, int, int, int, int>> Q;
	Q.push({ 1, 1, 0, 0, 0 }); V[1][1][0][0] = 1;
	while (Q.size())
	{
		auto [a, b, c, d, e](Q.front()); Q.pop();
		if (a == n && b == m && e) r = min(r, d);
		for (i = 0; i < 4; i++)
		{
			int y(a + dy[i]), x(b + dx[i]);
			if (y && x && y <= n && x <= m && M[y][x] ^ 1 && !V[y][x][c][e | M[y][x]])
				V[y][x][c][e | M[y][x]] = 1, Q.push({ y, x, c, d + 1, e | M[y][x] });
		}
		for (i = 1; c < k && i < 6; i++)
			for (j = 1; j < 6; j++)
				if (C[i][j])
				{
					int y(a - 3 + i), x(b - 3 + j);
					if (y > 0 && x > 0 && y <= n && x <= m && M[y][x] ^ 1 && !V[y][x][c + 1][e | M[y][x]])
						V[y][x][c + 1][e | M[y][x]] = 1, Q.push({ y, x, c + 1, d + 1, e | M[y][x] });
				}
	}
	cout << (r == 1e9 ? -1 : r);
}
int main()
{
	in();
	sv();
}
