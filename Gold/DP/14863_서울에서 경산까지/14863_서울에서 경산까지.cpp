#include<bits/stdc++.h>
using namespace std;

struct {int a, b, c, d;}x[101];
int n, k, dp[103][100005];

int f(int p, int q)
{
	if(q > k)
	    return -2e9;
	if(p == n + 1)
	    return 0;
	int& t(dp[p][q]);
	if(t == -1)
		t = 0, t = max(x[p].b + f(p + 1, q + x[p].a), x[p].d + f(p + 1, q + x[p].c));
	return t;
}
int main()
{
	memset(dp, -1, sizeof dp);
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	    cin >> x[i].a>> x[i].b >> x[i].c >> x[i].d;
	cout << f(0, 0);
}
