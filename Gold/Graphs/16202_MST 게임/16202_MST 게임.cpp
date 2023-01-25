#include<bits/stdc++.h>
using namespace std;

struct E
{
	int p, q, w;
	bool operator<(E& e) { return w < e.w; }
}Eg[10001];
int P[1001];
int n, m, k, i;

void in()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	for (; i < m; i++)
		cin >> Eg[i].p >> Eg[i].q, Eg[i].w = i + 1;
	sort(Eg, Eg + m);
}
int f(int p) { return P[p] = P[p] == p ? p : f(P[p]); }
int main()
{
	in();
	for (i = 0; i < k; i++)
	{
		iota(P, P + 1001, 0);
		int c{}, s{}, j{i};
		for (; j < m; j++)
		{
			int p(f(Eg[j].p)), q(f(Eg[j].q));
			if (p ^ q)
				c++, s += Eg[j].w, p > q ? P[p] = q : P[q] = p;
		}
		cout << (c ^ n - 1 ? 0 : s) << ' ';
	}
}
