#include <bits/stdc++.h>
using namespace std;

int n, m, k, i, j, r(2e9), a[2001][2001][2];
char M[2001][2001][2];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (i = 1; i < 2001; i++)
		for (j = 1; j < 2001; j++)
		{
			M[i][j][0] = (i & 1 && j & 1) || (!(i & 1) && !(j & 1)) ? 'B' : 'W';
			M[i][j][1] = (i & 1 && j & 1) || (!(i & 1) && !(j & 1)) ? 'W' : 'B';
		}
	cin >> n >> m >> k;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
		{
			char c; cin >> c;
			a[i][j][0] = a[i - 1][j][0] + a[i][j - 1][0] - a[i - 1][j - 1][0] + (M[i][j][0] != c);
			a[i][j][1] = a[i - 1][j][1] + a[i][j - 1][1] - a[i - 1][j - 1][1] + (M[i][j][1] != c);
		}
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			if (i >= k && j >= k)
				r = min({ r, a[i][j][0] - a[i - k][j][0] - a[i][j - k][0] + a[i - k][j - k][0], a[i][j][1] - a[i - k][j][1] - a[i][j - k][1] + a[i - k][j - k][1] });
	cout << r;
}
