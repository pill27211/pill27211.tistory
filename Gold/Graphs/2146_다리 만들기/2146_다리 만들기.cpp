#include<bits/stdc++.h>
#define F for (i = 1; i <= n; i++) for (j = 1; j <= n; j++)
using namespace std;

int dy[]{ -1, 1, 0, 0 }, dx[]{ 0, 0, -1, 1 };
int n, i, j, c(1), r(1e9), M[101][101];

void f()
{
	queue <pair<int, int>> Q;
	Q.push({ i, j }); M[i][j] = ++c;
	while (Q.size())
	{
		auto [a, b](Q.front()); Q.pop();
		for (int i{}; i < 4; i++)
		{
			int y(a + dy[i]), x(b + dx[i]);
			if (y && x && y <= n && x <= n && M[y][x] == 1)
				M[y][x] = c, Q.push({ y, x });
		}
	}
}
void sv()
{
	queue <pair<int, int>> Q;
	int D[101][101]{};
	Q.push({ i, j }), D[i][j] = 1;
	while (Q.size())
	{
		auto [a, b](Q.front()); Q.pop();
		if (M[a][b] && M[a][b] ^ c) r = min(r, D[a][b] - 2);
		for (int i{}; i < 4; i++)
		{
			int y(a + dy[i]), x(b + dx[i]);
			if (y && x && y <= n && x <= n && !D[y][x])
				if (D[y][x] = D[a][b] + (M[y][x] != c); D[y][x] - 2 < r)
					Q.push({ y, x });
		}
	}
}
int main()
{
	cin >> n;
	F
		scanf("%d", &M[i][j]);
	F
		if (M[i][j] == 1)
			f();
	c = 1;
	F
		if (M[i][j] == c + 1)
			++c, sv();
	cout << r;
}
