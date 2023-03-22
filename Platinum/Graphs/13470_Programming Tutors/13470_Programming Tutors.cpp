#include<bits/stdc++.h>
#define N 201
using namespace std;

vector <int> Gr[N];
int n, a[N], b[N], D[N], V[N];

int f(int p)
{
	for (int i : Gr[p])
		if (!V[i])
			if (V[i] = 1, !D[i] || f(D[i]))
				return D[i] = p, 1;
	return 0;
}
int main()
{
	cin >> n;
	for (int i(1); i <= n * 2; i++)
		cin >> a[i] >> b[i];
	int p{}, q(1e9), r{};
	while (p <= q)
	{
		int t{}, m((p + q) >> 1);
		for (int i(1); i <= n; i++)
			for (int j(n + 1); j <= n * 2; j++)
				if (abs(a[i] - a[j]) + abs(b[i] - b[j]) <= m)
					Gr[i].push_back(j);

		for (int i(1); i <= n; t += f(i++))
			memset(V, 0, sizeof V);
		for (int i(1); i <= n * 2; i++)
			Gr[i].clear(), D[i] = 0;

		t == n ? r = m, q = m - 1 : p = m + 1;
	}
	cout << r;
}
