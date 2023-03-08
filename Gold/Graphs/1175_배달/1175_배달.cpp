#include<bits/stdc++.h>
using namespace std;

int dy[]{ -1, 1, 0, 0 }, dx[]{ 0, 0, -1, 1 };
queue <tuple<int, int, int, int, int>> Q;
int n, m, i, j, r;
char M[51][51], V[51][51][4][4];

void in()
{
	cin >> n >> m;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
		{
			cin >> M[i][j];
			if (M[i][j] == 'S') Q.push({ i, j, 4, 0, 0 });
			if (M[i][j] == 'C') M[i][j] = 97 + r++;
		}
}
void sv()
{
	r = 1e9;
	while (Q.size())
	{
		auto [a, b, c, d, e](Q.front()); Q.pop();
		if (d == 3) r = min(r, e);
		for (i = 0; i < 4; i++)
			if (i ^ c)
			{
				int y(a + dy[i]), x(b + dx[i]);
				if (y && x && y <= n && x <= m && M[y][x] ^ '#' && !V[a][b][i][d])
					V[a][b][i][d] = 1, Q.push({ y, x, i, d | (M[y][x] > 96 ? 1 << (M[y][x] - 97) : 0), e + 1 });
			}
	}
	cout << (r == 1e9 ? -1 : r);
}
int main()
{
	in(); sv();
}
