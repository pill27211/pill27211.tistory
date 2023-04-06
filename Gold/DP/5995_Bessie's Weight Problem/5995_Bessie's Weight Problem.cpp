#include<bits/stdc++.h>
using namespace std;

int n, h, dp[45001];

int main()
{
	cin >> h >> n; dp[0] = 1;
	for (int o, i; n--;)
	{
		cin >> o;
		for (i = h - o; !!~i; i--)
			if (dp[i])
				dp[i + o] = 1;
	}
	for (int i(h); i; i--)
		if (dp[i])
			cout << i, exit(0);
}
