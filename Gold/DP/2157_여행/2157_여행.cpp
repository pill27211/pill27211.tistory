#include<bits/stdc++.h>
#define N 301
using namespace std;

int n, m, k, Gr[N][N], dp[N][N];

int f(int p, int q)
{
	if (p == n && !q)
		return 0;
	if (dp[p][q] == -1)
	{
		dp[p][q] = -2e9;
		for (int i = p + 1; i <= n; i++)
			if (Gr[p][i])
				dp[p][q] = max(dp[p][q], Gr[p][i] + f(i, q - 1));
	}
	return dp[p][q];
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(dp, -1, sizeof dp);
	cin >> n >> m >> k;
	while (k--)
	{
		int a, b, c; cin >> a >> b >> c;
		Gr[a][b] = max(Gr[a][b], c);
	}
	for(int i = 1; i <= m; i++)
		k = max(k, f(1, i - 1));
	cout << k;
}
