#include<bits/stdc++.h>
using namespace std;

int a[18][18], dp[18][1 << 18], pt[18][1 << 18];
int n, m, i, j, w;

void in()
{
	memset(dp, -1, sizeof dp);
	cin >> n >> m;
	while (m--)
		cin >> i >> j >> w, a[i - 1][j - 1] = w;
}
int f1(int p, int q)
{
	if (q == (1 << n) - 1)
		return dp[p][q] = a[p][0] ? a[p][0] : 2e9;
	int& t(dp[p][q]), i{}, k;
	if (t == -1)
		for (t = 2e9; i < n; i++)
			if (a[p][i] && !(q & (1 << i)))
			{
				k = max(a[p][i], f1(i, q | (1 << i)));
				if (t > k)
					t = k, pt[p][q] = i;
			}
	return t;
}
int main()
{
	in();
	w = f1(0, 1);
	if (w != 2e9)
	{
		cout << w << '\n';
		for (i = w = 0, j = 1; w < n; j |= (1 << i), w++)
			cout << i + 1 << ' ', i = pt[i][j];
	}
	else cout << -1;
}
