#include <bits/stdc++.h>
#define N 1001
using namespace std;

struct { int p, q, w; } pt[N][N];
int n, w, a[N], b[N], dp[N][N];

int f(int p, int q, int u)
{
	if (u == w + 1) return 0;
	int& t(dp[p][q]);
	if (t == -1)
	{
		t = 2e9;
		int x = f(u, q, u + 1) + (p ? abs(a[u] - a[p]) + abs(b[u] - b[p]) : a[u] - 1 + b[u] - 1);
		int y = f(p, u, u + 1) + (q ? abs(a[u] - a[q]) + abs(b[u] - b[q]) : n - a[u] + n - b[u]);
		if (t > x) t = x, pt[p][q] = { u, q, 1 };
		if (t > y) t = y, pt[p][q] = { p, u, 2 };
	}
	return t;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(dp, -1, sizeof dp);
	cin >> n >> w;
	for (int i = 1; i <= w; i++)
		cin >> a[i] >> b[i];
	cout << f(0, 0, 1) << '\n';
	int p{}, q{};
	while (pt[p][q].w)
	{
		cout << pt[p][q].w << '\n';
		n = p; p = pt[p][q].p, q = pt[n][q].q;
	}
}
