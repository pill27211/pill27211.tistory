#include<bits/stdc++.h>
using namespace std;

struct E
{
	int p, q, w;
	bool operator<(E& e) { return w < e.w; }
}Eg[444];
int P[21];
int t, n, m, i, r;

int f(int p) { return P[p] = P[p] == p ? p : f(P[p]); }
int main()
{
	cin >> t;
	for (int o(1); o <= t; o++)
	{
		iota(P, P + 21, 0); r = 0;
		cin >> n >> m;
		for (i = 0; i < m; i++)
			scanf("%d %d %d", &Eg[i].p, &Eg[i].q, &Eg[i].w);
		sort(Eg, Eg + m);

		for (i = 0; i < m; i++)
		{
			int p(f(Eg[i].p)), q(f(Eg[i].q));
			if (p ^ q)
				r += Eg[i].w, p > q ? P[p] = q : P[q] = p;
		}
		printf("Case #%d: %d meters\n", o, r);
	}
}
