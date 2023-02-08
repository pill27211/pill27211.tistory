#include<bits/stdc++.h>
using namespace std;

int n, a[2001], dp[2001][2001];

int f(int p, int q, int u)
{
	if (p == n || q == n) return 0;
	int& t(dp[p][q]);
	if (t == -1)
	{
		t = 2e9;
		t = min(t, f(u, q, u + 1) + (p ? abs(a[u] - a[p]) : 0));
		t = min(t, f(p, u, u + 1) + (q ? abs(a[u] - a[q]) : 0));
	}
	return t;
}
int main()
{
	memset(dp, -1, sizeof dp);
	cin >> n;
	for (int i = 1; i <= n; scanf("%d", &a[i++]));
	cout << f(0, 0, 1);
}
