#include<bits/stdc++.h>
using namespace std;

int dy[]{ -1, 1, 0, 0, -1, -1, 1, 1, 0 }, dx[]{ 0, 0, -1, 1, -1, 1, 1, -1, 0 };
queue <pair<int, int>> WQ;
int i, j;
char M[9][9][9];

void in()
{
	fill(&M[0][0][0], &M[8][8][9], '.');
	for (i = 1; i < 9; i++)
		for (j = 1; j < 9; j++)
			if (cin >> M[0][i][j]; M[0][i][j] == '#')
				WQ.push({ i, j });
}
void f()
{
	for (j = 1; WQ.size(); j++)
		for (int l(WQ.size()); l--;)
		{
			auto [a, b](WQ.front()); WQ.pop();
			if (a + 1 < 9)
				M[j][a + 1][b] = '#', WQ.push({ a + 1, b });
		}
}
void sv()
{
	queue <tuple <int, int, int>> Q;
	bool V[9][9][9]{};
	Q.push({ 8, 1, 0 }); V[0][8][1] = 1;
	while (Q.size())
	{
		auto [a, b, c](Q.front()); Q.pop();	
		if (a == 1 && b == 8) cout << 1, exit(0);
		for (i = 0; i < 9; i++)
		{
			int y(a + dy[i]), x(b + dx[i]);
			if (y && x && y < 9 && x < 9 && !V[c + 1][y][x] && M[c][y][x] ^ '#' && M[c + 1][y][x] ^ '#')
				V[c + 1][y][x] = 1, Q.push({ y, x, min(7, c + 1) });
		}
	}
	cout << 0;
}
int main()
{
	in();
	f();
	sv();
}
