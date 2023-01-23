#include<bits/stdc++.h>
#define ll long long
using namespace std;

int dy[]{ -1, 1, 0, 0 }, dx[]{ 0, 0, -1, 1 };
int n, m, k, r, dp[101][101][82];
char a[101][101];
string s;

int f(int p, int q, int o)
{
	if (s.size() == o + 1)
		return 1;
	int& t(dp[p][q][o]), i{}, j{};
	if (t == -1)
		for (t = 0; i < 4; i++)
			for (j = 1; j <= k; j++)
			{
				int y(p + dy[i] * j), x(q + dx[i] * j);
				if (y > 0 && x > 0 && y <= n && x <= m && a[y][x] == s[o + 1])
					t += f(y, x, o + 1);
			}
	return t;
}
int main()
{
	memset(dp, -1, sizeof dp);
	cin >> n >> m >> k;
	for (int i(1); i <= n; i++)
		for (int j(1); j <= m; j++)
			cin >> a[i][j];
	cin >> s;
	for (int i(1); i <= n; i++)
		for (int j(1); j <= m; j++)
			if (a[i][j] == s[0])
				r += f(i, j, 0);
	cout << r;
}
