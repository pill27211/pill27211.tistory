#include<bits/stdc++.h>
using namespace std;

int dy[]{ -1, 1, 0, 0 }, dx[]{ 0, 0, -1, 1 };
int n, i, j, r, M[101][101];

int f(int p, int q)
{
	if (M[1][1] < p || M[1][1] > q) return 0;
	queue <pair<int, int>> Q;
	bool V[101][101]{};
	Q.push({ 1, 1 }), V[1][1] = 1;
	while (Q.size())
	{
		auto [a, b](Q.front()); Q.pop();
		for (i = 0; i < 4; i++)
			if (int y(a + dy[i]), x(b + dx[i]); y && x && y <= n && x <= n && !V[y][x])
				if(M[y][x] >= p && M[y][x] <= q)
					V[y][x] = 1, Q.push({ y, x });
	}
	return V[n][n];
}
int main()
{
	for (cin >> n, i = 1; i <= n; i++)
		for (j = 1; j <= n; cin >> M[i][j++]);
	for (int p{}, q(201); p <= q;)
	{
		int m((p + q) >> 1), c{};
		for (j = 0; !c && j + m < 201; j++)
				c = f(j, j + m);
		c ? q = m - 1, r = m : p = m + 1;
	}
	cout << r;
}
