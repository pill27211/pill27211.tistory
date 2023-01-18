#include<bits/stdc++.h>
using namespace std;

int n, k, c, u, a[16][16], dp[1 << 16];
string s;

int f(int p, int q)
{
	if (p >= k)
		return 0;
	int& t(dp[q]), i{}, j{};
	if (t == -1)
		for (t = 2e9; i < n; i++)
			if (q & (1 << i))
				for (j = 0; j < n; j++)
					if (!(q & (1 << j)))
						t = min(t, f(p + 1, q | (1 << j)) + a[i][j]);
	return t;
}
int main()
{
	memset(dp, -1, sizeof dp);
	cin >> n;
	for (int i{}; i < n; i++)
		for (int j{}; j < n; cin >> a[i][j++]);
	cin >> s >> k;

	for (int i{}; i < (int)s.size(); i++)
		if (s[i] == 'Y')
			c++, u |= (1 << i);
	cout << (!k || c ? f(c, u) : -1);
}
