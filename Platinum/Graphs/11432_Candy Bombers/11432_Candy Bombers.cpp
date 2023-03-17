#include<bits/stdc++.h>
#define N 201
using namespace std;

vector <int> Gr[N];
int t, n, m, r, D[N], V[N];

int f(int p)
{
	for(int i : Gr[p])
		if (!V[i])
			if (V[i] = 1; !D[i] || f(D[i]))
				return D[i] = p, 1;
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	for (int o(1); o <= t; o++)
	{
		cin >> m >> n; r = 0;
		for (int i(1), k; i <= n; i++)
		{
			cin >> k;
			for (int j; k--;)
				cin >> j, Gr[i].push_back(j);
		}
		for (int i(1); i <= n; i++)
			memset(V, 0, sizeof V), r += f(i);
		cout << "Data Set " << o << ":\n" << r << '\n' << '\n';
		for (int i{}; i < N; i++)
			Gr[i].clear(), D[i] = 0;
	}
}
