#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll M[101][101][2], dp[101][101];
int n, m, k, i, j;

ll f(int p, int q)
{
	if ((!p && !q) || dp[p][q] ^ -1)
		return dp[p][q];
	dp[p][q] = 0;
	if (!M[p][q][0] && p - 1 >= 0)
		dp[p][q] += f(p - 1, q);
	if (!M[p][q][1] && q - 1 >= 0)
		dp[p][q] += f(p, q - 1);
	return dp[p][q];
}
int main()
{
	cin >> m >> n >> k;
	memset(dp, -1, sizeof dp);
	while (k--)
	{
		int a, b, c, d; cin >> a >> b >> c >> d;
		(b ^ d) ? M[max(b, d)][a][0] = 1 : M[b][max(a, c)][1] = 1;
	}
	dp[0][0] = 1; f(n, m);
	cout << dp[n][m];
}