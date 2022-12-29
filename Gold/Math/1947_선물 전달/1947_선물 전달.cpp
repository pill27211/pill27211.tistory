#include<bits/stdc++.h>

long long n, dp[1000001]{ 0, 0, 1, 2 };
int main()
{
	for (n = 4; n <= 1e6; n++)
		dp[n] = (dp[n - 1] + dp[n - 2]) * (n - 1) % 1000000000;
	std::cin >> n;
	std::cout << dp[n];
}