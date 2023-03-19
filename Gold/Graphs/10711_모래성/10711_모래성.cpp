#include<bits/stdc++.h>
#define N 1001
using namespace std;

int dy[]{ -1, 1, 0, 0, -1, -1, 1, 1 }, dx[]{ 0, 0, -1, 1, -1, 1, -1, 1 };
queue <pair<int, int>> Q;
char D[N][N], M[N][N];
int h, w, r;

void in()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> h >> w;
	for (int i(1); i <= h; i++)
		for (int j(1); j <= w; j++)
		{
			cin >> M[i][j];
			if (M[i][j] == '.') Q.push({ i, j });
		}
}
void sv()
{
	while (Q.size())
	{
		int l(Q.size()); r++;
		while (l--)
		{
			auto [a, b](Q.front()); Q.pop();
			for (int i{}; i < 8; i++)
			{
				int y(a + dy[i]), x(b + dx[i]);
				if (y && x && y <= h && x <= w && M[y][x] >= 48)
					if (++D[y][x] >= M[y][x] - 48)
						Q.push({ y, x }), M[y][x] = 0;
			}
		}
	}
	cout << r - 1;
}
int main()
{
	in();
	sv();
}
