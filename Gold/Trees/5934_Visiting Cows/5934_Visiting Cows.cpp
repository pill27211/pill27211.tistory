#include<bits/stdc++.h>
using namespace std;

vector <int> Gr[50001];
int n, dp[50001][2];

int f(int p, int q, int o)
{
	int& t(dp[p][q]);
	if (!~t)
	{
		t = q;
		for (int i : Gr[p])
			if (i ^ o)
				t += q ? f(i, 0, p) : max(f(i, 0, p), f(i, 1, p));
	}
	return t;
}
int main()
{
	memset(dp, -1, sizeof dp);
	cin >> n;
	for (int o(1), i, j; o < n; o++)
		cin >> i >> j, Gr[i].push_back(j), Gr[j].push_back(i);
	cout << max(f(1, 0, 0), f(1, 1, 0));
}
