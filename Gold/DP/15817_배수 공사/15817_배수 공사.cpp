#include<bits/stdc++.h>
using namespace std;

int n, x, i, j, dp[10001]{ 1 };

int main()
{
	cin >> n >> x;
	while (n--)
	{
		int a, b;
		cin >> a >> b;
		for (i = x; i >= 0; i--)
			for (j = 1; j <= b; j++)
				if(i >= a * j)
					dp[i] += dp[i - a * j];
	}
	cout << dp[x];
}
