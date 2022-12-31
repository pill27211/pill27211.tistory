#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, k, i, j, l, a[5][5], r[5][5];

void f(ll a[][5], ll b[][5])
{
	ll t[5][5]{};
	for (i = 0; i < n; i++)
		for (j = 0; j < n; t[i][j] %= 1000, j++)
			for (l = 0; l < n; l++)
				t[i][j] += (a[i][l] * b[l][j]);
	memcpy(a, t, sizeof t);
}
int main()
{
	cin >> n >> k;
	for (; i < n; r[i][i] = 1, i++)
		for (j = 0; j < n; cin >> a[i][j++]);
	while (k)
	{
		if (k & 1)
			f(r, a);
		f(a, a); k >>= 1;
	}
	for (i = 0; i < n; puts(""), i++)
		for (j = 0; j < n; cout << r[i][j++] << ' ');
}
