#include<bits/stdc++.h>
using namespace std;

int dy[] = { -1, 1, 0, 0 }, dx[] = { 0, 0, -1, 1 };
int n, i, j, r, a[501][501], dp[501][501];

int f(int p, int q)
{
	if (dp[p][q])
		return dp[p][q];
	int i = 0, j = 0;
	for (; i < 4; i++)
	{
		int y = p + dy[i], x = q + dx[i];
		if (y && x && y <= n && x <= n && a[y][x] > a[p][q])
			j = max(j, f(y, x));
	}
	return dp[p][q] = j + 1;
}
int main()
{
	cin >> n;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			r = max(r, f(i, j));
	cout << r;
}