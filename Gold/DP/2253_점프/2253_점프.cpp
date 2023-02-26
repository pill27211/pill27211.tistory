#include<bits/stdc++.h>
using namespace std;

int n, m, a[10001], dp[10001][150];

int f(int p, int q)
{
	if (p > n || a[p]) return 2e9;
	if (p == n) return 0;
	int& t(dp[p][q]);
	if (!~t)
	{
		t = 2e9;
		if (q - 1) t = min(t, f(p + q - 1, q - 1) + 1);
		t = min({ t, f(p + q, q) + 1, f(p + q + 1, q + 1) + 1 });
	}
	return t;
}
int main()
{
	memset(dp, -1, sizeof dp);
	cin >> n >> m;
	for (int i{}; m; m--)
		cin >> i, a[i] = 1;
	cout << (a[2] ? -1 : (f(2, 1) == 2e9 ? -1 : f(2, 1) + 1));
}
