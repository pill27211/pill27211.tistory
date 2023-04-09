#include<bits/stdc++.h>
using namespace std;

int n, c, i, a[51];

int main()
{
	for (cin >> n; i < n; cin >> a[i++]);
	for (int r{}; ;)
	{
		if (!accumulate(a, a + 51, 0)) cout << r, exit(0);
		for (c = i = 0; i < n; i++)
			if (a[i] & 1)
				r += c = 1, a[i]--;
		if (!c)
			for (i = 0, r++; i < n; a[i++] >>= 1);
	}
}
