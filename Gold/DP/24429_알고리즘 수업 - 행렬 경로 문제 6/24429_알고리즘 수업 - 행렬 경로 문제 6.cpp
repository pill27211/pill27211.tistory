#include<bits/stdc++.h>
#define N 1001
using namespace std;

vector <pair<int, int>> V;
int n, k, i, j, a[N][N], dp[N][N];

void f(int p, int q, int y, int x)
{
	for (int i = p; i <= y; i++)
		for (int j = q; j <= x; j++)
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; cin >> a[i][j++]);
	cin >> k;
	while (k--)
		cin >> i >> j, V.emplace_back(i, j);
	sort(V.begin(), V.end());
	i = j = 1;
	for (auto& v : V)
	{
		auto [p, q] = v;
		f(i, j, p, q);
		i = p, j = q;
		if (!dp[p][q])
			cout << -1, exit(0);
	}
	f(i, j, n, n);
	cout << (dp[n][n] ? dp[n][n] : -1);
}
