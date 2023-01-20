#include<bits/stdc++.h>
using namespace std;

struct E
{
	int p, q, w;
	bool operator<(E& e) { return w < e.w; }
};
int P[51];
int n, m, i, r;

int f(int p) { return P[p] = P[p] == p ? p : f(P[p]); }
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	while (cin >> n, n)
	{
		iota(P, P + 51, 0); r = 0;
		cin >> m;
		vector <E> Eg(m);
		for (i = 0; i < m; i++)
			cin >> Eg[i].p >> Eg[i].q >> Eg[i].w;
		sort(Eg.begin(), Eg.end());
		for (auto& i : Eg)
		{
			int p(f(i.p)), q(f(i.q));
			if (p ^ q)
				r += i.w, p > q ? P[p] = q : P[q] = p;
		}
		cout << r << '\n';
	}
}
