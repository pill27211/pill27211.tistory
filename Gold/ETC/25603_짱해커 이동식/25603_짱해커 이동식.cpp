#include<bits/stdc++.h>

int n, k, r, a[100001];
int i, p, q(1e9);

int main()
{
	for (std::cin >> n >> k; i < n; scanf("%d", &a[i++]));
	while (p <= q)
	{
		int m((p + q) >> 1), f{}, j{};
		for (i = 0; !f && i < n; j = a[i++] > m ? j + 1 : 0, f = j >= k);
		!f ? q = m - 1, r = m : p = m + 1;
	}
	std::cout << r;
}
