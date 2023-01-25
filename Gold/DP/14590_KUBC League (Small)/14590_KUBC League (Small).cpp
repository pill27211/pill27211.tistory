#include<bits/stdc++.h>
using namespace std;

int n, i, j, a[20][20], dp[20][1 << 20];

void in()
{
	memset(dp, -1, sizeof dp);
	cin >> n;
	for (; i < n; i++)
		for (j = 0; j < n; cin >> a[i][j++]);
}
int f1(int p, int q)
{
	int& t(dp[p][q]), i{};
	if (t == -1)
		for (t = 0; i < n; i++)
			if (a[p][i] && !(q & (1 << i)))
				t = max(t, f1(i, q | (1 << i)) + 1);
	return t;
}
void f2(int p, int q)
{
	for (int i(0); i < n; i++)
		if (a[p][i] && !(q & (1 << i)) && dp[p][q] == dp[i][q | (1 << i)] + 1)
			cout << i + 1 << ' ', f2(i, q | (1 << i)), i = n;
}
int main()
{
	in();
	cout << f1(0, 1) + 1 << '\n' << 1 << ' ';
	f2(0, 1);
}
