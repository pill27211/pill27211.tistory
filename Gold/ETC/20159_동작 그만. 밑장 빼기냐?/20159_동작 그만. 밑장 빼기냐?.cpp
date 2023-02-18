#include<bits/stdc++.h>
#define N 100001
using namespace std;

int n, i, r, b[N], c[N];

int main()
{
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> r;
		b[i] += b[i - 1], c[i] += c[i - 1];
		i & 1 ? b[i] += r : c[i] += r;
	}
	for (r = b[n], i = 1; i <= n; i++)
		r = max(r, i & 1 ? b[i - 2] + c[n] - c[i] : b[i - 1] + c[n - 1] - c[i - 1]);
	cout << r;
}
