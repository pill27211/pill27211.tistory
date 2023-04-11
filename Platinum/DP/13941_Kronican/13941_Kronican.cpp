#include<bits/stdc++.h>
using namespace std;

int n, k, a[21][21], dp[1 << 20];

int f(int q, int c)
{
	if (c == k) return 0;
	int& t(dp[q]), i{}, j{};
	if (!~t)
		for (t = 1e9; j < n; j++)
			if(q & (1 << j))
				for (i = 0; i < n; i++)
					if (i ^ j && q & (1 << i))
						t = min(t, f(q ^ (1 << j), c - 1) + a[j][i]);
	return t;
}
int main()
{
	memset(dp, -1, sizeof dp);
	cin >> n >> k;
	for (int i{}; i < n; i++)
		for (int j{}; j < n; cin >> a[i][j++]);
	cout << f((1 << n) - 1, n);
}
