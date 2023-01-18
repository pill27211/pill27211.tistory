#include<bits/stdc++.h>
using namespace std;

int n, dp[16][1 << 16];
string s[16];

int f(int p, int q, int k)
{
	int& t(dp[p][q]), i{};
	if (t == -1)
		for (t = 0; i < n; i++)
			if (!(q & (1 << i)) && (!q || s[p].back() == s[i].front()))
				t = max(t, f(i, q | (1 << i), k + s[i].size()));
	return max(t, k);
}
int main()
{
	memset(dp, -1, sizeof dp);
	cin >> n;
	for (int i{}; i < n; cin >> s[i++]);
	cout << f(0, 0, 0);
}
