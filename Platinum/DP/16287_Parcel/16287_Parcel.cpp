#include<bits/stdc++.h>
using namespace std;

int w, n, i, j, k, a[5001], c[400001];

int main()
{
	cin >> w >> n;
	for (; i < n; scanf("%d", &a[i++]));
	sort(a, a + n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < i; c[a[i] + a[j++]] = 1);
		for (j = i + 2; j < n; j++)
		{
			k = w - a[i + 1] - a[j];
			if (k >= 0 && k <= 400000 && c[k])
				cout << "YES", exit(0);
		}
	}
	cout << "NO";
}
