#include<bits/stdc++.h>
using namespace std;

struct E
{
	int N, V1, V2, W;
	bool operator<(struct E& e) { return W < e.W; }
}t, Eg[500000];
vector <int> An;
int n, m, i, c, P[200001];

void f0()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	iota(P, P + 200001, 0);
	cin >> n >> m;
	if (m == n - 1) cout << "NO", exit(0);
	for (i = 0; i < m; i++)
		cin >> Eg[i].V1 >> Eg[i].V2 >> Eg[i].W, Eg[i].N = i + 1;
	sort(Eg, Eg + m);
}
int f1(int p) { return P[p] = P[p] == p ? p : f1(P[p]); }
void f2(int p, int q) { p > q ? P[p] = q : P[q] = p; }
void f3()
{
	for (i = 0; i < m; i++)
	{
		int p(f1(Eg[i].V1)), q(f1(Eg[i].V2));
		if (p == q)
		{
			t = Eg[i];
			continue;
		}
		f2(p, q);
		if (c) An.push_back(Eg[i].N);
	}
	c++;
}
int main()
{
	f0(); f3();
	iota(P, P + 200001, 0);
	f2(t.V1, t.V2); f3();
	An.push_back(t.N);
	cout << "YES\n";
	for (int& i : An) cout << i << ' ';
}
