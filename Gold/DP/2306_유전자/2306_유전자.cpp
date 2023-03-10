#include<bits/stdc++.h>
using namespace std;

int n, dp[501][501];
string s;

int f(int p, int q)
{
	int& t(dp[p][q]), i(p);
	if (!~t)
	{
		if(t = 0; (s[p] == 'a' && s[q] == 't') || (s[p] == 'g' && s[q] == 'c')) t = 2 + f(p + 1, q - 1);
		for (; i < q; i++) t = max(t, f(p, i) + f(i + 1, q));
	}
	return t;
}
int main()
{
	memset(dp, -1, sizeof dp);
	cin >> s; n = s.size();
	cout << f(0, n - 1);
}
