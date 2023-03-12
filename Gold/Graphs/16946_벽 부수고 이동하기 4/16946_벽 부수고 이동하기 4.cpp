#include<bits/stdc++.h>
#define F for (i = 1; i <= n; i++) for (j = 1; j <= m; j++)
#define N 1001
using namespace std;

int dy[]{ -1, 1, 0, 0 }, dx[]{ 0, 0, -1, 1 };
int n, m, i, j, k, M[N][N], R[N][N], X[N][N];
bool V[N][N];

void f(int c = 1)
{
	queue <pair<int, int>> Q, S;
	Q.push({ i, j }), S.push({ i, j });
	V[i][j] = 1; k++;
	while (Q.size())
	{
		auto [a, b](Q.front()); Q.pop();
		for (int i{}; i < 4; i++)
		{
			int y(a + dy[i]), x(b + dx[i]);
			if (y && x && y <= n && x <= m && M[y][x] && !V[y][x])
			{
				c++, V[y][x] = 1;
				Q.push({ y, x }), S.push({ y, x });
			}
		}
	}
	while (S.size())
	{
		auto [a, b](S.front()); S.pop();
		M[a][b] = c; X[a][b] = k;
	}
}
int main()
{
	cin >> n >> m;
	F
		scanf("%1d", &M[i][j]), M[i][j] ^= 1;
	F
		if (M[i][j] && !V[i][j])
			f();
	F
		if (!M[i][j])
		{
			set <int> S;
			int s(1);
			for (int l{}; l < 4; l++)
			{
				int y(i + dy[l]), x(j + dx[l]);
				if (y && x && y <= n && x <= m && !S.count(X[y][x]))
					s += M[y][x], S.insert(X[y][x]);
			}
			R[i][j] = s % 10;
		}
	for (i = 1; i <= n; puts(""), i++)
		for (j = 1; j <= m; j++)
			printf("%d", R[i][j]);
}
