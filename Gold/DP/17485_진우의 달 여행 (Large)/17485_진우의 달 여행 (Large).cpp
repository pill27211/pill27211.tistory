#include<bits/stdc++.h>
using namespace std;

int a[1001][1001], dp[1001][1001][3], d[] = { -1, 0, 1 };
int n, m, i, j, r = 2e9;

int f(int p, int q, int w)
{
	if (dp[p][q][w])
		return dp[p][q][w];
	int j = 2e9;
	for (int i = 0; i < 3; i++)
	{
		int y = p + 1, x = q + d[i];
		if (i ^ w && x && y <= n && x <= m)
			j = min(j, f(y, x, i));
	}
	return dp[p][q][w] = a[p][q] + (j == 2e9 ? 0 : j);
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			cin >> a[i][j];
	for (i = 1; i <= m; i++)
		for (j = 0; j < 3; j++)
			r = min(r, f(1, i, j));
	cout << r;
}