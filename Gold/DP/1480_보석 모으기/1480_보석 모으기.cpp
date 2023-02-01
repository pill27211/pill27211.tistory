#include<bits/stdc++.h>
using namespace std;

int n, m, c, a[13], dp[1 << 13][10][21];

int f(int w, int p, int q)
{
	if (p == m) return 0;
	int& t(dp[w][p][q]), i{};
	if (t == -1)
		for (t = 0; i < n; i++)
			if (!(w & (1 << i)))
				t = max(t, q < a[i] ? f(w, p + 1, c) : f(w | (1 << i), p, q - a[i]) + 1);
	return t;
}
int main()
{
	memset(dp, -1, sizeof dp);
	cin >> n >> m >> c;
	for (int i{}; i < n; cin >> a[i++]);
	cout << f(0, 0, c);
}
