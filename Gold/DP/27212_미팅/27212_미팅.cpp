#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[1001][1001];
int a[1001], b[1001], C[20][20];
int n, m, c, i, j;

ll f(int p, int q)
{
	if (p == n + 1 || q == m + 1)
		return 0;
    ll& t(dp[p][q]);
	if (t == -1)
        t = 0, t = max({C[a[p]][b[q]] + f(p + 1, q + 1), f(p, q + 1), f(p + 1, q)});
	return t;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
	memset(dp, -1, sizeof dp);
	cin >> n >> m >> c;
	for (i = 1; i <= c; i++)
		for (j = 1; j <= c; cin >> C[i][j++]);
	for (i = 1; i <= n; cin >> a[i++]);
	for (i = 1; i <= m; cin >> b[i++]);
	cout << f(1, 1);
}
