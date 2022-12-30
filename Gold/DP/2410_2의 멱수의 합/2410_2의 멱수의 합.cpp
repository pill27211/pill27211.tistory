#include<bits/stdc++.h>
#define N 1000001
using namespace std;

int i, j, dp[N]{1};
int main()
{
	for (i = 0; (1 << i) < N; i++)
		for (j = 1 << i; j < N; j++)
			dp[j] = (dp[j] + dp[j - (1 << i)]) % (int)1e9;
	cin >> i; cout << dp[i];
}
