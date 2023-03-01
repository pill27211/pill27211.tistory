#include<bits/stdc++.h>
using namespace std;

int	n, k, i, j, l, M(10000), a[101], dp[101][4][4];

int main()
{
	cin >> n >> k;
	for (; i < k; i++)
		cin >> j >> l, a[j] = l;
	fill(&dp[2][1][1], &dp[2][3][4], 1);
	for (i = 1; i < 4; i++)
		for (j = 1; j < 4; j++)
			if ((a[2] && a[2] ^ i) || (a[1] && a[1] ^ j))
				dp[2][i][j] = 0;
	for (i = 3; i <= n; i++)
	{
		for (j = 1; j < 4; j++)
			if(!a[i] || a[i] == j)
				for (l = 1; l < 4; dp[i][j][l++] %= M)
					for (k = 1; k < 4; k++)
						if (!(j == l && j == k))
							dp[i][j][l] += dp[i - 1][l][k];
	}
	cout << accumulate(&dp[n][1][1], &dp[n][3][4], 0) % M;
}
