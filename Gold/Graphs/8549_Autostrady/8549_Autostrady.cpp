#include<bits/stdc++.h>
#define N 100001
using namespace std;

struct E
{
	int p, q, w;
	bool operator<(E& e) { return w < e.w; }
}Eg[N];
int P[N];
int n, m, i, r;

int f(int p) { return P[p] = P[p] == p ? p : f(P[p]); }
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	iota(P, P + N, 0);
	cin >> n >> m;
	for (i = 0; i < m; i++)
		cin >> Eg[i].p >> Eg[i].q >> Eg[i].w;
	sort(Eg, Eg + m);

	for (i = 0; i < m; i++)
	{
		int p(f(Eg[i].p)), q(f(Eg[i].q));
		if (p ^ q)
			r = Eg[i].w, p > q ? P[p] = q : P[q] = p;
	}
	cout << r << '\n';
}
