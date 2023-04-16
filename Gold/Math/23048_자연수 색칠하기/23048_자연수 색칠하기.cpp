#include<bits/stdc++.h>
using namespace std;

int n, r(1), i(2), c[500001]{ 0, 1 };

int main()
{
	for (cin >> n; i <= n; i++)
		if (!c[i])
		{
			c[i] = ++r;
			for (int j(i + i); j <= n; j += i)
				c[j] = r;
		}
	cout << r << '\n';
	for (i = 1; i <= n; printf("%d ", c[i++]));
}
