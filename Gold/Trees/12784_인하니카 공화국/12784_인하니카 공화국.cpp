#include<bits/stdc++.h>
using namespace std;

vector <pair<int, int>> Gr[1001];
int t, n, m, dp[1001];

int f(int p, int o)
{
	int& t(dp[p]), s;
	if (!~t)
	{
		t = 0;
		for (auto& [a, b] : Gr[p])
			if (a ^ o)
				s = min(Gr[a].size() > 1 ? f(a, p) : (int)2e9, b), t += s;
	}
	return t;
}
int main()
{
	cin >> t;
	while (t--)
	{
		for (int i{}; i < 1001; i++) dp[i] = -1, Gr[i].clear();
		cin >> n >> m;
		for (int i, j, w; m--;)
			cin >> i >> j >> w, Gr[i].emplace_back(j, w), Gr[j].emplace_back(i, w);
		cout << f(1, 0) << '\n';
	}
}
