#include<bits/stdc++.h>
using namespace std;

int dy[]{ 0, 0, 0, 1, -1 }, dx[]{ 0, 1, -1, 0, 0 };
struct S { int y, x, w; }p, q;
int n, m, i, j, M[101][101], V[101][101][5];

void in()
{
	cin >> n >> m;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; cin >> M[i][j++]);
	cin >> p.y >> p.x >> p.w >> q.y >> q.x >> q.w;
}
void f()
{
	queue <S> Q;
	Q.push(p), V[p.y][p.x][p.w] = 1;
	while (Q.size())
	{
		auto [a, b, c](Q.front()); Q.pop();
		for (j = i = 1; i < 4; i++)
		{
			int y(a + dy[c] * i), x(b + dx[c] * i);
			if (i == j && y > 0 && x > 0 && y <= n && x <= m && !M[y][x])
				j++, !V[y][x][c] ? Q.push({ y, x, c }), V[y][x][c] = V[a][b][c] + 1 : 1;
		}
		for (i = 1; i < 5; i++)
			if (!V[a][b][i])
				V[a][b][i] = V[a][b][c] + (c < 3 ? (i < 3 ? 2 : 1) : (i > 2 ? 2 : 1)), Q.push({ a, b, i });
	}
}
int main()
{
	in();
	f();
	cout << V[q.y][q.x][q.w] - 1;
}
