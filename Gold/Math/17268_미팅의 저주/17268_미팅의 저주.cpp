#include<bits/stdc++.h>
using namespace std;

long long n, i, dp[10001]{1, 1, 2};
int main()
{
    for (n = 3; n < 10001; n++)
	for (i = 0; i < n; dp[n] %= 987654321, i++)
		dp[n] += dp[i] * dp[n - i - 1];
    cin >> n, cout << dp[n >> 1] << '\n';
}
