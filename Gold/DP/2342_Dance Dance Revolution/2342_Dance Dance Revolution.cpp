#include<bits/stdc++.h>
using namespace std;

int i, a[100005], dp[100005][5][5];

int f(int n, int p, int q)
{
	if (n == i) return 0;
	int& t(dp[n][p][q]), k(a[n] & 1);
	if (!t)
	{
		t = 2e9;
		if (p == a[n] || q == a[n])
			t = min(t, f(n + 1, p, q) + 1);
		if (!p)
			t = min(t, f(n + 1, a[n], q) + 2);
		if (!q)
			t = min(t, f(n + 1, p, a[n]) + 2);
		t = min(t, f(n + 1, a[n], q) + (p & 1 ? 3 + k : 4 - k));
		t = min(t, f(n + 1, p, a[n]) + (q & 1 ? 3 + k : 4 - k));
	}
	return t;
}
int main()
{
	while (scanf("%d", &a[++i]), a[i]);
	cout << f(1, 0, 0);
}
