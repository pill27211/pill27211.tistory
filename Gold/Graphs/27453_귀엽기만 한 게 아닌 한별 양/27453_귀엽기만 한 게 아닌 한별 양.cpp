#include <bits/stdc++.h>
using namespace std;

int dy[]{ -1, 1, 0, 0 }, dx[]{ 0, 0, -1, 1 };
queue <tuple<int, int, int, int, int>> Q;
map <char, int> D{ {'S', 0}, {'H', 0} };
int n, m, k, i, j;
char M[1001][1001];
bool V[1001][1001][4];

void in()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
		{
			cin >> M[i][j];
			if (M[i][j] == 'S') Q.push({ i, j, 0, 0, 0 });
		}
	for (i = 0; i < 10; i++)
		D[i + 48] = i;
}
void f()
{
	while (Q.size())
	{
		auto [a, b, c, d, e](Q.front()); Q.pop();
		if (M[a][b] == 'H') cout << e, exit(0);
		for (i = 0; i < 4; i++)
		{
			int y(a + dy[i]), x(b + dx[i]);
			if (y && x && y <= n && x <= m && !V[a][b][i] && (y ^ c || x ^ d) && M[y][x] ^ 'X' && D[M[a][b]] + D[M[c][d]] + D[M[y][x]] <= k)
				V[a][b][i] = 1, Q.push({ y, x, a, b, e + 1 });
		}
	}
}
int main()
{
	in();
	f();
	cout << -1;
}
