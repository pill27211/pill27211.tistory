#include<bits/stdc++.h>
#define F for (i = 1; i <= n; i++) for (j = 1; j <= m; j++)
using namespace std;

int dy[]{ -1, 1, 0, 0 }, dx[]{ 0, 0, -1, 1 };
int n, m, c, r(1e9), i, j, D[15][51][51], d[15][15], dp[15][1 << 15];
char M[51][51];

void f1(int p)
{
	queue <pair<int, int>> Q;
	Q.push({ i, j }); M[i][j] = p + 97;
	while (Q.size())
	{
		auto [a, b](Q.front()); Q.pop();
		for (int i{}; i < 4; i++)
			if (int y(a + dy[i]), x(b + dx[i]); y && x && y <= n && x <= m && M[y][x] == 'X')
				M[y][x] = p + 97, Q.push({ y, x });
	}
}
void f2(int p)
{
	priority_queue <tuple<int, int, int>> Q;
	Q.push({ 0, i, j }); d[p][p] = 0;
	while (Q.size())
	{
		auto [a, b, c](Q.top());
		a *= -1, Q.pop();
		if (a <= D[p][b][c])
			for (int i{}; i < 4; i++)
			{
				int y(b + dy[i]), x(c + dx[i]);
				if (y && x && y <= n && x <= m && M[y][x] ^ '.')
					if (int k(a + (M[y][x] == 'S')); k < D[p][y][x])
					{
						D[p][y][x] = k, Q.push({ -k, y, x });
						if (M[y][x] > 96) d[p][M[y][x] - 97] = min(d[p][M[y][x] - 97], k);
					}
			}
	}
}
int f3(int p, int q)
{
	if (q == (1 << c) - 1) return 0;
	int& t(dp[p][q]), i{};
	if (!~t)
		for (t = 1e9; i < c; i++)
			if (!(q & (1 << i)))
				t = min(t, f3(i, q | (1 << i)) + d[p][i]);
	return t;
}
int main()
{
	fill(&D[0][0][0], &D[14][50][51], 1e9);
	fill(&d[0][0], &d[14][15], 1e9);
	memset(dp, -1, sizeof dp);
	cin >> n >> m;
	F
		cin >> M[i][j];
	F
		if (M[i][j] == 'X')
			f1(c++);
	c = 0;
	F
		if (M[i][j] > 96 && M[i][j] - 97 == c)
			f2(c++);
	for (i = 0; i < c; i++) r = min(r, f3(i, 1 << i));
	cout << r;
}
