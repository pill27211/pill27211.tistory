#include<bits/stdc++.h>
#define N 100001
using namespace std;

struct E
{
	int p, q, w;
	bool operator<(E& e) { return w < e.w; }
}Eg[N * 10];
int P[N];
int v, e, i, r;

int f(int p) { return P[p] = P[p] == p ? p : f(P[p]); }
void in()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	iota(P, P + N, 0);
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
			r += v = Eg[i].w, (p > q ? P[p] = q : P[q] = p);
	}
	cout << r - v;
}
int main()
{
	in();
	sv();
}
