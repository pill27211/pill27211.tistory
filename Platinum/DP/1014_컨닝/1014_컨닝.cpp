#include<bits/stdc++.h>
using namespace std;

int a[10], dp[10][1 << 10];
int c, n, m, i, j;
char ch;

int f(int p, int q)
{
	if (p == n)
		return 0;
	int& t(dp[p][q]), i{}, j, k(1);
	if (t == -1)
		for (t = 0; i < (1 << m); k = 1, i++)
			if (!(a[p] & i))
			{
				for (j = 0; j < m; j++)
					if (i & (1 << j) && ((i & (1 << (j - 1))) || q & (1 << (j - 1)) || q & (1 << (j + 1))))
						k = 0, j = m;
				if (k)
					t = max(t, f(p + 1, i) + __builtin_popcount(i));
			}
	return t;
}
int main()
{
	cin >> c;
	while (c--)
	{
		memset(dp, -1, sizeof dp), memset(a, 0, sizeof a);
		cin >> n >> m;
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				cin >> ch, a[i] |= ch == 'x' ? (1 << j) : 0;
		cout << f(0, 0) << '\n';
	}
}
