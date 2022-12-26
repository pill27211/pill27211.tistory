#include<bits/stdc++.h>
using namespace std;

int n, m, r, i, j, a[1001][1001];
int main()
{
	cin >> n >> m;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
		{
			scanf("%1d", &a[i][j]);
			if (a[i][j])
				a[i][j] = min({ a[i - 1][j], a[i][j - 1], a[i - 1][j - 1] }) + 1, r = max(r, a[i][j]);
		}
	cout << r * r;
}