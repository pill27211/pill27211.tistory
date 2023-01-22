#include<bits/stdc++.h>
using namespace std;

int a[1001][1001][3];
int n, m, q, i, j, k;
char c;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> q;
	for (; i < n; i++)
		for (j = 0; j < m; a[i + 1][j++ + 1][c == 'J' ? 0 : (c == 'O' ? 1 : 2)]++)
			for (cin >> c, k = 0; k < 3; k++)
				a[i + 1][j + 1][k] = a[i + 1][j][k] + a[i][j + 1][k] - a[i][j][k];
	while (q--)
	{
		cin >> i >> j >> n >> m;
		for (k = 0; k < 3; k++)
			cout << a[n][m][k] - a[i - 1][m][k] - a[n][j - 1][k] + a[i - 1][j - 1][k] << ' ';
		cout << '\n';
	}
}
