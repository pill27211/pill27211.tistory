#include<bits/stdc++.h>
using namespace std;

int dy[]{ -1, 1, 0, 0 }, dx[]{ 0, 0, -1, 1 };
priority_queue <tuple <int, int, int>> Q;
int n, m, i, j, p, q, D[505][505];
char M[505][505];

void in()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
		{
			cin >> M[i][j]; D[i][j] = 2e9;
			if (M[i][j] == 'S')
				Q.push({ 0, i, j }), D[i][j] = 0;
			if (M[i][j] == 'E')
				p = i, q = j;
		}
}
int f1(int p, int q)
{
	for (int k{}; k < 4; k++)
		if (M[p + dy[k]][q + dx[k]] == '#')
			return 1;
	return 0;
}
void f2()
{
	while (Q.size())
	{
		auto [a, b, c](Q.top());
		Q.pop(), a *= -1;
		if (D[b][c] >= a)
			for (i = 0; i < 4; i++)
			{
				int y(b + dy[i]), x(c + dx[i]);
				if (y && x && y <= n && x <= m && M[y][x] ^ '#')
				{
					j = a + (f1(b, c) && f1(y, x) ? 0 : 1);
					if (D[y][x] > j)
						D[y][x] = j, Q.push({ -j, y, x });
				}
			}
	}
}
int main()
{
	in();
	f2();
	cout << D[p][q];
}
