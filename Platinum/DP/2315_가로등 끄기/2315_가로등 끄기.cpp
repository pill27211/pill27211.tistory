#include<bits/stdc++.h>
#define N 1001
using namespace std;

int n, m, a[N], b[N], dp[N][N][2];

int f(int p, int q, int w)
{
	if (!p || q > n) return 2e9;
	if (p == 1 && q == n) return 0;
	int& t(dp[p][q][w]), k(w ? q : p), l(b[n] - b[q] + b[p - 1]);
	if (t == -1)
		t = 2e9, t = min(f(p, q + 1, 1) + l * (a[q + 1] - a[k]), f(p - 1, q, 0) + l * (a[k] - a[p - 1]));
	return t;
}
int main()
{
	memset(dp, -1, sizeof dp);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &a[i], &b[i]), b[i] += b[i - 1];
	cout << f(m, m, 0);
}
