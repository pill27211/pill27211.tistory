#include<bits/stdc++.h>
using namespace std;

int n, a[5001], dp[5001][10][10][10];

int f(int p, int x, int y, int z)
{
	if (p == n) return 0;
	int& t(dp[p][x][y][z]);
	if (!~t)
	{
		t = 1e9;
		t = min(t, f(p + 1, a[p + 1], y, z) + min(abs(x - a[p + 1]), 10 - abs(x - a[p + 1])));
		t = min(t, f(p + 1, x, a[p + 1], z) + min(abs(y - a[p + 1]), 10 - abs(y - a[p + 1])));
		t = min(t, f(p + 1, x, y, a[p + 1]) + min(abs(z - a[p + 1]), 10 - abs(z - a[p + 1])));
	}
	return t;
}
int main()
{
	memset(dp, -1, sizeof dp);
	cin >> n;
	for (int i(1); i <= n; cin >> a[i++]);
	cout << f(0, 0, 0, 0);
}
