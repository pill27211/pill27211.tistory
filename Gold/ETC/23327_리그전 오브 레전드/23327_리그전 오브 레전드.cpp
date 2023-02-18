#include<bits/stdc++.h>
using namespace std;

long long a[100005], b[100005];
int n, q, i, j;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> q;
	for (i = 1; i <= n; i++)
		cin >> a[i], a[i] += a[i - 1], b[i] = b[i - 1] + a[i - 1] * (a[i] - a[i - 1]);
	while (q--)
		cin >> i >> j, cout << b[j] - a[i - 1] * (a[j] - a[i - 1]) - b[i - 1] << '\n';
}
