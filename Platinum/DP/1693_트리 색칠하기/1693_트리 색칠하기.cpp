#include<bits/stdc++.h>
#define N 100001
using namespace std;

int n, i, j, k, dp[N][19];
vector <int> Gr[N];

int f(int p, int q, int x)
{
	if (dp[p][q])
		return dp[p][q];
	int t{};
	for (int i : Gr[p])
		if (i ^ x)
		{
			int m = 2e9;
			for (int j = 1; j < 19; j++)
				if (j ^ q)
					m = min(m, f(i, j, p));
			t += m;
		}
	return dp[p][q] = t + q;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (; k < n - 1; k++)
		cin >> i >> j, Gr[i].push_back(j), Gr[j].push_back(i);
	for (k = 2e9, i = 1; i < 19; k = min(k, f(1, i++, 1)));
	cout << k;
}
