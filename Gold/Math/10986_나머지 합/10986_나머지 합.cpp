#include<bits/stdc++.h>
using namespace std;

long long n, m, r, i, a[1000001], c[1001];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (i = 1; i <= n; c[a[i++]]++)
		cin >> a[i], a[i] = (a[i] + a[i - 1]) % m;

	for (i = 0; i < m; i++)
		r += c[i] * (c[i] - 1) / 2;
	cout << r + c[0];
}
