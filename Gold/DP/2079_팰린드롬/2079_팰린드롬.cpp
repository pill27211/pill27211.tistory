#include<bits/stdc++.h>
using namespace std;

string s;
int n, dp[2000];
bool c[2000][2000];

int f(int p)
{
	if (p == n) return 0;
	int& t(dp[p]), i(p);
	if (!~t)
		for (t = 1e9; i < n; i++)
			if (c[p][i])
				t = min(t, f(i + 1) + 1);
	return t;
}
int main()
{
	memset(dp, -1, sizeof dp);
	cin >> s; n = s.size();
	for (int i(n - 1), j{}; i >= 0; i--)
		for (c[i][i] = 1, j = i + 1; j < n; j++)
			c[i][j] = (i + 1 == j || c[i + 1][j - 1]) && s[i] == s[j];
	cout << f(0);
}
