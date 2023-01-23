#include<bits/stdc++.h>
#define N 200001
using namespace std;

pair <int, int> a[N];
int n, i, seg[N];
long long r;

void f1(int p, int q)
{
	while (p <= N - 1)
		seg[p] += q, p += p & -p;
}
int f2(int p)
{
	int t{};
	while (p)
		t += seg[p], p -= p & -p;
	return t;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (i = 1; i <= n; i++)
		cin >> a[i].first, a[i].second = i;
	sort(a + 1, a + n + 1);
	for (i = 1; i <= n; i++)
		r += f2(N - 1) - f2(a[i].second), f1(a[i].second, 1);
	cout << r;
}
