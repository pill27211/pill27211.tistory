#include<bits/stdc++.h>
using namespace std;

queue <tuple <int, int, int>> Q;
queue <pair<int, int>> _Q;
int dy[]{ -1, 1, 0, 0 }, dx[]{ 0, 0, -1, 1 };
int n, m, k, i, j, M[2001][2001];

void in()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
		{
			cin >> M[i][j];
			if (M[i][j] == 3) M[i][j] = 5, _Q.push({ i, j });
			if (M[i][j] == 4) M[i][j] = 0, Q.push({ i, j, 0 });
		}
}
void f1()
{
	while (k--)
	{
		j = _Q.size();
		while (j--)
		{
			auto [a, b](_Q.front()); _Q.pop();
			for (i = 0; i < 4; i++)
			{
				int y(a + dy[i]), x(b + dx[i]);
				if (y && x && y <= n && x <= m && M[y][x] ^ 5)
					M[y][x] = 5, _Q.push({ y, x });
			}
		}
	}
}
void f2()
{
	while (Q.size())
	{
		auto [a, b, c](Q.front()); Q.pop();
		for (i = 0; i < 4; i++)
		{
			int y(a + dy[i]), x(b + dx[i]);
			if (y && x && y <= n && x <= m && (!M[y][x] || M[y][x] == 2))
				!M[y][x] ? (M[y][x] = 5, Q.push({ y, x, c + 1 })) : (cout << c + 1, exit(0));
		}
	}
}
int main()
{
	in(); f1(); f2();
	cout << -1;
}
