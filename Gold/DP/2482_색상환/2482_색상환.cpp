#include<bits/stdc++.h>

int i, j, dp[1001][1001];

int main()
{
	dp[4][1] = 4, dp[4][2] = 2;
	dp[5][1] = 5, dp[5][2] = 5;
	for (i = 6; i < 1001; i++)
		for (dp[i][1] = i, j = 2; j < 1001; j++)
			dp[i][j] = (dp[i - 1][j] + dp[i - 2][j - 1]) % 1000000003;
	std::cin >> i >> j;
	std::cout << dp[i][j];
}
