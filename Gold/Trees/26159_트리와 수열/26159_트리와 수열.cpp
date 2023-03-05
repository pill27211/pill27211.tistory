#include<bits/stdc++.h>
#define N 100001
using namespace std;

vector <int> Gr[N];
int n, i, r, a[N];
long long dp[N];

int f(int p)
{
	dp[p] = 1;
	for (int i : Gr[p])
		if (!dp[i])
			dp[p] += f(i);
	return dp[p];
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int p, q; i < n - 1; i++)
		cin >> p >> q, Gr[p].push_back(q), Gr[q].push_back(p);
	for (i = 1; i < n; cin >> a[i++]);
	sort(a, a + n); f(1);
	for (i = 1; i <= n; i++)
		dp[i] *= (n - dp[i]);
	sort(dp + 1, dp + n + 1, greater<>());
	for (i = 1; i < n; i++)
		r = (r + dp[i] * a[i]) % 1000000007;
	cout << r;
}
