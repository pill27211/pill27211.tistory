#include<bits/stdc++.h>
using namespace std;

long long n, i, dp[5001]{1, 1, 2};
int main()
{
    for (n = 3; n < 5001; n++)
	for (i = 0; i < n; dp[n] %= 1000000007, i++)
	    dp[n] += dp[i] * dp[n - i - 1];
    cin >> n;
    while(n--)
        cin >> i, cout << (i & 1 ? 0 : dp[i >> 1]) << '\n';
}
