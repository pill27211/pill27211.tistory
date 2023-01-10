#include<bits/stdc++.h>
using namespace std;

int dy[] = { -1, 1, 0, 0 }, dx[] = { 0, 0, -1, 1 };
int n, m, dp[51][51], V[51][51];
char M[51][51];

int f(int p, int q)
{
	if (p < 1 || q < 1 || p > n || q > m || M[p][q] == 'H')
		return 0;
	if (V[p][q])
		cout << -1, exit(0);
	int& t = dp[p][q];
	if (t == -1)
	{
		t = 0;
		V[p][q] = 1;
		for (int i = 0; i < 4; i++)
			t = max(t, 1 + f(p + dy[i] * (M[p][q] - 48), q + dx[i] * (M[p][q] - 48)));
		V[p][q] = 0;
	}
	return t;
}
int main()
{
	memset(dp, -1, sizeof dp);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> M[i][j];
	cout << f(1, 1);
}
