#include<bits/stdc++.h>
using namespace std;

int a[1001][3], dp[1001][3][3];
int n, i, j, r = 2e9;

int f(int p, int q)
{
	if (dp[p][q][i])
		return dp[p][q][i];
	int o = 0, t = 2e9;
	if (p == n)
		return dp[p][q][i] = q ^ i ? a[p][q] : 2e9;

	for (; o < 3; o++)
		if (o ^ q)
			t = min(t, f(p + 1, o));
	return dp[p][q][i] = a[p][q] + t;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (i = 1; i <= n; i++)
		for (j = 0; j < 3; j++)
			cin >> a[i][j];
	for (i = 0; i < 3; i++)
		r = min(r, f(1, i));
	cout << r;
}