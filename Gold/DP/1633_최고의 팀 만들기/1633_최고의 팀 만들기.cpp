#include<bits/stdc++.h>
using namespace std;

int i, a[1001], b[1001], dp[1001][16][16];

int f(int n, int p, int q)
{
	auto& t = dp[n][p][q];
	if (t ^ -1)
		return t;
	if (p == 15 && q == 15)
		return t = 0;
	t = 0;
	if (p < 15)
		t = max(t, a[n] + f(n + 1, p + 1, q));
	if (q < 15)
		t = max(t, b[n] + f(n + 1, p, q + 1));
	return t = max(t, f(n + 1, p, q));
}
int main()
{
	memset(dp, -1, sizeof dp);
	while (cin >> a[i] >> b[i]) i++;
	cout << f(0, 0, 0);
}
