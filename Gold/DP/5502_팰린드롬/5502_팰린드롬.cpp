#include <bits/stdc++.h>
using namespace std;

int n, i, j, dp[5001][5001];
string s;

int main()
{
	cin >> n >> s;
	for (i = n - 1; i >= 0; i--)
		for (j = i + 1; j < n; j++)
			dp[i][j] = s[i] ^ s[j] ? min(dp[i][j - 1], dp[i + 1][j]) + 1 : dp[i + 1][j - 1];
	cout << dp[0][n - 1];
}
