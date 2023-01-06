#include<bits/stdc++.h>
using namespace std;

int t, n, i, j, a[101], dp[10001];
vector <int> V(1);

int main()
{
	fill(dp + 1, dp + 10001, 2e9);
	cin >> t >> n;
	for (i = 1; i <= n; V.push_back(a[i]), i++)
		for (cin >> a[i], j = 1; j < i; j++)
			V.push_back(a[i] + a[j]);
  
	for (i = 1; i < (int)V.size(); i++)
		for (j = V[i]; j <= t; j++)
			dp[j] = min(dp[j], dp[j - V[i]] + 1);
	cout << (dp[t] == 2e9 ? -1 : dp[t]);
}
