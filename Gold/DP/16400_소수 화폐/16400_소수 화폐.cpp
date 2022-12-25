#include <bits/stdc++.h>

int n, i, p[40001], dp[40001];
int main()
{
	for (i = 2; i <= 40000; i++)
		if (!p[i])
		{
			for (n = i + i; n <= 40000; n += i)
				p[n] = 1;
			for (++dp[i], n = i; n <= 40000; n++)
				dp[n] = (dp[n] + dp[n - i]) % 123456789;
		}
	std::cin >> n;
	std::cout << dp[n];
}
