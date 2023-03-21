#include<bits/stdc++.h>
using namespace std;

struct E
{
	int p, q, w;
	bool operator<(E& e) { return w < e.w; }
}Eg[10001];
int n, m, i, r, P[2001];

int f(int p) { return P[p] = P[p] == p ? p : f(P[p]); }
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	iota(P, P + 2001, 0);
	cin >> n >> m;
	for (i = 0; i < m; i++)
		cin >> Eg[i].p >> Eg[i].q >> Eg[i].w;
	sort(Eg, Eg + m);

	for (i = 0; i < m; i++)
		if (int p(f(Eg[i].p)), q(f(Eg[i].q)); p ^ q)
			r = Eg[i].w, p > q ? P[p] = q : P[q] = p;
	cout << r << '\n';
}
