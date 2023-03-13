#include<bits/stdc++.h>
#define ll long long
using namespace std;

int dy[]{ -1, 1, 0, 0 }, dx[]{ 0, 0, -1, 1 };
ll M[501][501], T[501][501];
ll r, c, k, i, j;
ll X, p, q(1e18), an;

void in()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> r >> c >> k >> X;
	for (i = 1; i <= r; i++)
		for (j = 1; j <= c; cin >> M[i][j++]);
}
int f(ll m, int u = 0)
{
	queue <pair<int, int>> Q;
	memcpy(T, M, sizeof M);
	for (i = 1; i <= r; i++)
		for (j = 1; j <= c; j++)
			for (int l{}; l < 4; l++)
				if (int y(i + dy[l]), x(j + dx[l]); y && x && y <= r && x <= c)
					if (T[y][x] - T[i][j] > m)
						T[i][j] = X, Q.push({ i, j });
	while (Q.size())
	{
		auto [a, b](Q.front());
		u++, Q.pop();
		for (i = 0; i < 4; i++)
			if (int y(a + dy[i]), x(b + dx[i]); y && x && y <= r && x <= c && T[a][b] - T[y][x] > m)
				T[y][x] = X, Q.push({ y, x });
	}
	return u;
}
void sv()
{
	while (p <= q)
	{
		ll m((p + q) >> 1);
		f(m) > k ? p = m + 1 : (q = m - 1, an = m);
	}
	cout << an;
}
int main()
{
	in();
	sv();
}
