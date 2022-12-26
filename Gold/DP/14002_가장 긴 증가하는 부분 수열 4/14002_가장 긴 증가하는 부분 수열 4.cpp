#include<bits/stdc++.h>
using namespace std;

vector <int> dp[1001];
int a[1001];
int n, i, j, r = 1;

int main()
{
	cin >> n;
	for (i = 1; i <= n; i++)
		cin >> a[i], dp[i].push_back(a[i]);
	for (i = 2; i <= n; i++)
	{
		vector <int> t;
		for (j = i - 1; j; j--)
			if (a[j] < a[i] && dp[j].size() > t.size())
				t = dp[j];
		for (int a : t)
			dp[i].push_back(a);
		if (dp[r].size() < dp[i].size())
			r = i;
	}
	sort(dp[r].begin(), dp[r].end());
	cout << dp[r].size() << '\n';
	for (int i : dp[r])
		cout << i << ' ';
}