#include<bits/stdc++.h>
#define D double
using namespace std;

D a[20][20], dp[1 << 20];
int n;

D f(int p, int q)
{
	if (p == n)
		return 1;
	D& t(dp[q]); int i{};
	if(t == -1.0)
		for (t = -2; i < n; i++)
			if (!(q & (1 << i)))
				t = max(t, (a[p][i] / 100) * f(p + 1, q | (1 << i)));
	return t;
}
int main()
{
	fill(dp, dp + (1 << 20), -1.0);
	cin >> n;
	for (int i{}; i < n; i++)
		for (int j{}; j < n; cin >> a[i][j++]);
	printf("%.10lf", f(0, 0) * 100);
}
