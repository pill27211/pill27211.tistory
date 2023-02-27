#include<bits/stdc++.h>
#define N 100001
using namespace std;

int n, q, o, i, j, a[N], seg[N];

void f1(int p, int q)
{
	while (p <= N - 1)
		seg[p] += q, p += p & -p;
}
int f2(int p)
{
	int r{};
	while (p)
		r += seg[p], p -= p & -p;
	return r;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> q;
	for (i = 1; i <= n; i++)
		cin >> a[i], f1(i, a[i] != a[i - 1]);
	while (q--)
	{
		cin >> o >> i >> j;
		if (o & 1)
			cout << f2(j) - f2(i - 1) + !(f2(i) - f2(i - 1)) << '\n';
		else
		{
			if (a[i] ^ a[i - 1] && j == a[i - 1]) f1(i, -1);
			else if (a[i] == a[i - 1] && j ^ a[i - 1]) f1(i, 1);
			if (i < n && a[i] ^ a[i + 1] && j == a[i + 1]) f1(i + 1, -1);
			else if (i < n && a[i] == a[i + 1] && j ^ a[i + 1]) f1(i + 1, 1);
			a[i] = j;
		}
	}
}
