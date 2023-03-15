#include<bits/stdc++.h>
using namespace std;

int dy[]{ -1, 1, 0, 0 }, dx[]{ 0, 0, -1, 1 };
int r, c, k, an, M[1001][1001];
queue <pair<int, int>> Q;

void in()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> r >> c >> k;
	for (int i(1); i <= r; i++)
		for (int j(1); j <= c; cin >> M[i][j++]);
}
int f(int m, int s = 0)
{
	bool V[1001][1001]{};
	Q.push({ 0, 0 }); V[0][0] = 1;
	while (Q.size())
	{
		auto [a, b](Q.front()); Q.pop();
		for (int i{}; i < 4; i++)
		{	
			int y(a + dy[i]), x(b + dx[i]);
			if (!!~y && !!~x && y <= r && x <= c + 1 && !V[y][x] && M[y][x] <= m)
				V[y][x] = 1, Q.push({ y, x }), s += M[y][x] > 0;
		}
	}
	return s;
}
void sv()
{
	int p{}, q(1e6), m;
	while(p <= q)
		m = (p + q) >> 1, f(m) >= k ? q = m - 1, an = m : p = m + 1;
	cout << an;
}
int main()
{
	in();
	sv();
}
