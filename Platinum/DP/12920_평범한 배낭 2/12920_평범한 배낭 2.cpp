#include<bits/stdc++.h>
using namespace std;

vector <pair<int, int>> V(1);
int n, m, i, j, dp[1500][10001];

int main()
{
	cin >> n >> m;
	while(n--)
	{
		int a, b, c; cin >> a >> b >> c;
		for (i = 1; c > 0; c -= j, i <<= 1)
			j = min(i, c), V.emplace_back(a * j, b * j);
	}
	for (i = 1; i < (int)V.size(); i++)
		for (j = 1; j <= m; j++)
			dp[i][j] = j >= V[i].first ? max(dp[i - 1][j], dp[i - 1][j - V[i].first] + V[i].second) : dp[i - 1][j];
	cout << dp[V.size() - 1][m];
}
