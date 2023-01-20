#include<bits/stdc++.h>
using namespace std;

struct E
{
	int p, q, w;
	bool operator<(E& e) { return w < e.w; }
}Eg[100001];
int P[1001];
int v, e, i, r;

int f(int p) { return P[p] = P[p] == p ? p : f(P[p]); }
void in()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	iota(P, P + 1001, 0);
	cin >> v >> e;
	for (; i < e; i++)
		cin >> Eg[i].p >> Eg[i].q >> Eg[i].w;
}
void sv()
{
	sort(Eg, Eg + e);
	for (i = 0; i < e; i++)
	{
		int p(f(Eg[i].p)), q(f(Eg[i].q));
		if (p ^ q)
			r += Eg[i].w, (p > q ? P[p] = q : P[q] = p);
	}
	cout << r;
}
int main()
{
	in();
	sv();
}
