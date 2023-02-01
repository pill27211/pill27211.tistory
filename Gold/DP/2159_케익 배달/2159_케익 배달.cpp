#include<bits/stdc++.h>
#define ll long long
#define N 100001
using namespace std;

int dy[]{ 0, -1, 1, 0, 0 }, dx[]{ 0, 0, 0, -1, 1 };
int n, a[N], b[N];
ll dp[N][5];

ll f(int u, int w, int p, int q)
{
	if (u > n) return 0;
	ll& t(dp[u][w]), i{};
	if (!t)
		for (t = 1e18; i < 5; i++)
		{
			int y(a[u] + dy[i]), x(b[u] + dx[i]);
			if (y >= 0 && x >= 0 && y < N && x < N)
				t = min(t, f(u + 1, i, y, x) + abs(p - y) + abs(q - x));
		}
	return t;
}
int main()
{
	cin >> n >> a[0] >> b[0];
	for (int i{ 1 }; i <= n; i++)
		scanf("%d %d", &a[i], &b[i]);
	cout << f(1, 0, a[0], b[0]);
}
