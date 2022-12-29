#include<bits/stdc++.h>

long long n, i, j, dp[101][101][2];
int main()
{
	dp[2][0][0] = 2, dp[2][0][1] = 1, dp[2][1][1] = 1;
	for (i = 3; i < 101; i++)
		for (j = 0; j < i; j++)
		{
			dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1];
			dp[i][j][1] = dp[i - 1][j][0] + (j ? dp[i - 1][j - 1][1] : 0);
		}
	std::cin >> n;
	while (n--)
		std::cin >> i >> j, std::cout << dp[i][j][0] + dp[i][j][1] << '\n';
}
