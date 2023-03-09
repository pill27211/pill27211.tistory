#include<bits/stdc++.h>
#define N 200001
using namespace std;

int n, i, c[N], seg[N];
long long an;

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
	cin >> n;
	for (int i(1), j; i <= n; i++)
	{
		cin >> j;
		if (c[j]) f1(c[j], -1);
		an += f2(N) - f2(c[j]);
		f1(i, 1), c[j] = i;
	}
	cout << an;
}
