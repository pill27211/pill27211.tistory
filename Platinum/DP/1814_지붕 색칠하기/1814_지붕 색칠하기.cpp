#include<bits/stdc++.h>
#define N 10001
using namespace std;

vector <int> Gr[N], G[N];
int n, c, i, j, k, C[N], dp[N][15];

int f(int p, int q, int x)
{
	if (dp[p][q])
		return dp[p][q];
	int t{};
	for (int i : Gr[p])
		if (i ^ x)
		{
			int m = 2e9;
			for (int j = 0; j < c; j++)
				if (j ^ q)
					m = min(m, f(i, j, p));
			t += m;
		}
	return dp[p][q] = t + C[q];
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (; k < n - 1; k++)
		cin >> i >> j, Gr[i].push_back(j), Gr[j].push_back(i);
	cin >> c;
	for (i = 0; i < c; cin >> C[i++]);
	sort(C, C + c); c = min(c, 15);
	for (k = 2e9, i = 0; i < c; k = min(k, f(1, i++, 1)));
	cout << k;
}
