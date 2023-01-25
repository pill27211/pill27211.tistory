#include<bits/stdc++.h>
#define N 100001
using namespace std;

struct E
{
	int p, q, w;
	bool operator<(E& e) { return w < e.w; }
}Eg[N * 5];
int n, m, i, c, P[N];
long long s, k;

void in()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	iota(P, P + N, 0);
	cin >> n >> m;
	for (; i < m; i++)
		cin >> Eg[i].p >> Eg[i].q >> Eg[i].w, k += Eg[i].w;
	sort(Eg, Eg + m);
}
int f(int p) { return P[p] = P[p] == p ? p : f(P[p]); }
void sv()
{
	for(i = 0; i < m; i++)
	{
		int p(f(Eg[i].p)), q(f(Eg[i].q));
		if (p ^ q)
			c++, s += Eg[i].w, p > q ? P[p] = q : P[q] = p;
	}
	cout << (c ^ n - 1 ? -1 : k - s);
}
int main()
{
	in();
	sv();
}
