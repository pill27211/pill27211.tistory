#include<bits/stdc++.h>
using namespace std;

int dy[]{ -1, 1, 0, 0 }, dx[]{ 0, 0, -1, 1 };
int dp[16][1 << 16], D[16][1001][1001];
vector <pair<int, int>> V;
int n, m, k, r(2e9), i, j;
int p1, q1, p2, q2;
char M[1001][1001];

void in()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(dp, -1, sizeof dp); memset(D, -1, sizeof D);
	cin >> n >> m >> k;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
		{
			cin >> M[i][j];
			if (M[i][j] == 'N') V.push_back({ i, j });
			if (M[i][j] == 'U') p1 = i, q1 = j;
			if (M[i][j] == 'I') p2 = i, q2 = j;
		}
}
void f1(int p)
{
	queue <pair<int, int>> Q;
	Q.push({ i, j }); D[p][i][j] = 0;
	while (Q.size())
	{
		auto [a, b](Q.front()); Q.pop();
		for (int i{}; i < 4; i++)
		{
			int y(a + dy[i]), x(b + dx[i]);
			if (y && x && y <= n && x <= m && M[y][x] ^ '#' && !~D[p][y][x])
				D[p][y][x] = D[p][a][b] + 1, Q.push({ y, x });
		}
	}
}
int f2(int p, int q)
{
	if (q == (1 << k) - 1) return D[p][p2][q2];
	int& t(dp[p][q]), i{};
	if (!~t)
		for (t = 2e9; i < k; i++)
			if (!(q & (1 << i)))
				t = min(t, f2(i, q | (1 << i)) + D[p][V[i].first][V[i].second]);
	return t;
}
void sv()
{
	for (k = 0, i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			if (M[i][j] == 'N')
				f1(k++);
	for (i = 0; i < k; i++)
		r = min(r, f2(i, 1 << i) + D[i][p1][q1]);
	cout << r;
}
int main()
{
	in();
	sv();
}
