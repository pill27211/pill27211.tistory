#include<bits/stdc++.h>
#define D double
using namespace std;

struct { D x, y; }p[16];
D n, a[16][16], dp[16][1 << 16];

D f(int p, int q)
{
	if (q == (1 << int(n)) - 1)
		return a[p][0] ? a[p][0] : 2e8;
	D& t = dp[p][q]; int i{};
	if (!t)
		for (t = 2e8; i < n; i++)
			if (a[p][i] && !(q & (1 << i)))
				t = min(t, f(i, q | (1 << i)) + a[p][i]);
	return t;
}
int main()
{
	cin >> n;
	for (int i{}; i < n; i++)
	{
		cin >> p[i].x >> p[i].y;
		for (int j{}; j < i; j++)
			a[i][j] = a[j][i] = sqrt(pow((p[i].x - p[j].x), 2) + pow(p[i].y - p[j].y, 2));
	}
	printf("%.6lf", f(0, 1));
}
