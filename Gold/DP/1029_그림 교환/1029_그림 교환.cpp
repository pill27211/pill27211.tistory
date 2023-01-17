#include<bits/stdc++.h>
using namespace std;

int n, a[15][15], dp[15][10][1 << 15];

int f(int p, int q, int o, int c)
{
	int& t(dp[p][o][q]), i{};
	if (!t)
		for (t = -1; i < n; i++)
			if (a[p][i] >= o && !(q & (1 << i)))
				t = max(t, f(i, q | (1 << i), a[p][i], c + 1));
	return max(t, c);
}
int main()
{
	cin >> n;
	for (int i{}; i < n; i++)
		for (int j{}; j < n; scanf("%1d", &a[i][j++]));
	cout << f(0, 1, 0, 1);
}
