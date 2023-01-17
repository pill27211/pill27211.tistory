#include<bits/stdc++.h>
using namespace std;

int n, a[16][16], dp[16][1 << 16];

int f(int p, int q)
{
	if (q == (1 << n) - 1)
		return a[p][0] ? a[p][0] : 2e8;
	int& t = dp[p][q], i{};
	if (!t)
		for (t = 2e8; i < n; i++)
			if (a[p][i] && !(q & (1 << i)))
				t = min(t, f(i, q | (1 << i)) + a[p][i]);
	return t;
}
int main()
{
	cin >> n;
	for (int i{}; i < n; i++)
		for (int j{}; j < n; cin >> a[i][j++]);
	cout << f(0, 1);
}
