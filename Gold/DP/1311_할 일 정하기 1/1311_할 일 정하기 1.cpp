#include<bits/stdc++.h>
using namespace std;

int n, a[20][20], dp[20][1 << 20];

int f(int p, int q)
{
	if (p == n)
		return 0;
	int& t(dp[p][q]), i{};
	if (!t)
		for (t = 2e9; i < n; i++)
			if (!(q & (1 << i)))
				t = min(t, a[p][i] + f(p + 1, q | (1 << i)));
	return t;
}
int main()
{
	cin >> n;
	for (int i{}; i < n; i++)
		for (int j{}; j < n; cin >> a[i][j++]);
	cout << f(0, 0);
}
