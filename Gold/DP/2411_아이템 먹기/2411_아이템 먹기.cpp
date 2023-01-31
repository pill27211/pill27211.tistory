#include<bits/stdc++.h>
using namespace std;

int M[101][101], dp[101][101][101];
int n, m, a, b;

int f(int p, int q, int k)
{
	if (p == n && q == m) return !k;
	int& t(dp[p][q][k]);
	if (t == -1)
	{
		t = 0;
		if (p + 1 <= n && M[p + 1][q] ^ 2)
			t += f(p + 1, q, k - M[p + 1][q]);
		if (q + 1 <= m && M[p][q + 1] ^ 2)
			t += f(p, q + 1, k - M[p][q + 1]);
	}
	return t;
}
int main()
{
	memset(dp, -1, sizeof dp);
	cin >> n >> m >> a >> b;
	for (int i{}, j{}, k{}; k < a + b; k++)
		cin >> i >> j, M[i][j] = k < a ? 1 : 2;
	cout << f(1, 1, a);
}
