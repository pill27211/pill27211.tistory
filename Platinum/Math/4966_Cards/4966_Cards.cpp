#include<bits/stdc++.h>
#define N 501
using namespace std;

vector <int> Gr[N];
int D[N], a[N], V[N];
int n, m, i, j, r;

int f2(int p)
{
	for (auto& a : Gr[p])
		if (!V[a])
		{
			V[a] = true;
			if (!D[a] || f2(D[a]))
				return D[a] = p, 1;
		}
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	while (cin >> n >> m, (n && m))
	{
		for (i = 1; i <= n; cin >> a[i++]);
		for (i = 1; i <= m; i++)
		{
			int k; cin >> k;
			for (j = 1; j <= n; j++)
				if (gcd(a[j], k) > 1)
					Gr[j].emplace_back(i);
		}
		for (i = 1; i <= n; i++)
			memset(V, 0, sizeof V), r += f2(i);
		cout << r << '\n';
		for (i = 1; i < N; i++)
			Gr[i].clear(), D[i] = 0;
		r = 0;
	}
}