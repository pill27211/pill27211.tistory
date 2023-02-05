#include<bits/stdc++.h>
#define P pair<int, int>
using namespace std;

int dy[]{ -1, 1, 0, 0 }, dx[]{ 0, 0, -1, 1 };
int n, m, f, r(1), M[101][101], T[101][101];
vector <P> v[101][101];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m; T[1][1] = 1;
	while (m--)
	{
		int a, b, c, d; cin >> a >> b >> c >> d;
		v[a][b].push_back({ c, d });
	}
	while (!f)
	{
		queue <P> Q;
		bool V[101][101]{};
		Q.push({ 1, 1 }); V[1][1] = 1;
		f = 1;
		while (Q.size())
		{
			auto [a, b](Q.front()); Q.pop();
			for (auto& i : v[a][b])
				if (!T[i.first][i.second])
					f = 0, r++, T[i.first][i.second] = 1;
			for (m = 0; m < 4; m++)
			{
				int y(a + dy[m]), x(b + dx[m]);
				if (y && x && y <= n && x <= n && T[y][x] && !V[y][x])
					V[y][x] = 1, Q.push({ y, x });
			}
		}
	}
	cout << r;
}
