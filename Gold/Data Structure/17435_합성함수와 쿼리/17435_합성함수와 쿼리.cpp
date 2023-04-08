#include<bits/stdc++.h>
using namespace std;

int n, q, i(1), j, k, dp[200001][19];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (cin >> n; i <= n; cin >> dp[i++][0]);
	for (j = 1; j < 19; j++)
		for (i = 1; i <= n; i++)
			dp[i][j] = dp[dp[i][j - 1]][j - 1];
	for (cin >> q; q--; cout << j << '\n')
		for (cin >> i >> j, k = 0; i; i >>= 1, k++)
			if (i & 1)
				j = dp[j][k];
}
