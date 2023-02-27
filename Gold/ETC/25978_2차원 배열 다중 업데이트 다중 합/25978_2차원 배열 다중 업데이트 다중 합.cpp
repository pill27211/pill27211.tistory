#include<bits/stdc++.h>
using namespace std;

long long s[1005][1005], p[1005][1005];
int n, m, i, j, c;
int o, a, b, y, x, k;

void f()
{
	for(i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
		{
			p[i][j] += p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];
			s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + p[i][j];
		}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; cin >> s[i][j++]);
	while (m--)
	{
		cin >> o >> a >> b >> y >> x;
		a++, b++, y++, x++;
		if (o & 1)
		{
			cin >> k;
			p[a][b] += k, p[y + 1][x + 1] += k;
			p[a][x + 1] -= k, p[y + 1][b] -= k;
		}
		else
		{
			if (!c) c = 1, f();
			cout << s[y][x] - s[y][b - 1] - s[a - 1][x] + s[a - 1][b - 1] << '\n';
		}
	}
}
