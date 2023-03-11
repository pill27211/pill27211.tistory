#include<bits/stdc++.h>
using namespace std;

map <int, int> M;
int n, k, s, i, j;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	while (cin >> n >> k, n && k)
	{
		int p{}, r{}; M.clear();
		cin >> s; M[1] = 0;
		for (i = 2; i <= n; i++)
		{
			if (k == s) k = i - 1;
			cin >> j;
			if (j - 1 != s) p++;
			M[i] = p; s = j;
		}
		if (k == s) k = i - 1;
		for (auto& [a, b] : M)
			if (a ^ k && M[k] ^ b && M[M[k]] && M[b] && M[M[k]] == M[b])
				r++;
		cout << r << '\n';
	}
}
