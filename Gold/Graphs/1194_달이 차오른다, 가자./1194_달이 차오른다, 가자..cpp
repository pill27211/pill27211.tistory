#include<bits/stdc++.h>
using namespace std;

int dy[]{ -1, 1, 0, 0 }, dx[]{ 0, 0, -1, 1 };
int n, m, i(1), j, r(1e9), V[51][51][1 << 6];
queue <tuple <int, int, int, int>> Q;
char M[51][51];

void f()
{
	while (Q.size())
	{
		auto [a, b, c, d](Q.front()); Q.pop();
		if (M[a][b] == '1') r = min(r, d);
		for (i = 0; i < 4; i++)
		{
			int y(a + dy[i]), x(b + dx[i]);
			if (y && x && y <= n && x <= m && M[y][x] ^ '#' && !V[y][x][c])
			{
				auto& t(M[y][x]); V[y][x][c] = 1;
				if (t < 65) Q.push({ y, x, c, d + 1 });
				if (t >= 97) Q.push({ y, x, c | (1 << (t - 97)), d + 1 });
				else if (t >= 65 && c & (1 << (t - 65))) Q.push({ y, x, c, d + 1 });
			}
		}
	}
	cout << (r == 1e9 ? -1 : r);
}
int main()
{
	for (cin >> n >> m; i <= n; i++)
		for (j = 1; j <= m; j++)
		{
			cin >> M[i][j];
			if (M[i][j] == '0') V[i][j][0] = 1, Q.push({ i, j, 0, 0 });
		}
	f();
}
