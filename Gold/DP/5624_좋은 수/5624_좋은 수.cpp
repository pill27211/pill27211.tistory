#include<bits/stdc++.h>
#define N 200000
using namespace std;

int n, r, i, j, a[5001], c[N << 1 | 1];

int main()
{
	cin >> n;
	for (; i < n; i++)
	{
		scanf("%d", &a[i]);
		for (j = 0; j < i; j++)
			if (c[a[i] - a[j] + N])
				r++, j = n;
		for (j = 0; j <= i; j++)
				c[a[j] + a[i] + N] = 1;
	}
	cout << r;
}
