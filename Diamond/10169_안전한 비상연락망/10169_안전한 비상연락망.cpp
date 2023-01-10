#include <bits/stdc++.h>
#define ll long long
#define N 100001
using namespace std;

struct E
{
	int V1, V2, W;
	bool operator<(E& e) { return W < e.W; }
}Eg[N << 1], cEg[N << 1];
struct S { int p, q; };
map <pair<int, int>, ll> An;
vector <S> Gr[N];
vector <E> nEg;
int P[N], D[N], C[N];
int n, m, i, j, dp[N][18];
ll s;

void in()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	iota(P, P + N, 0);
	cin >> n >> m;
	for (i = 0; i < m; i++)
	{
		cin >> Eg[i].V1 >> Eg[i].V2 >> Eg[i].W;
		if (Eg[i].V1 > Eg[i].V2)
			swap(Eg[i].V1, Eg[i].V2);
	}
	memcpy(cEg, Eg, sizeof Eg);
	sort(Eg, Eg + m);
}
int f1(int p) { return P[p] = P[p] == p ? p : f1(P[p]); }
void f2()
{
	for (i = 0; i < m; i++)
	{
		int p = f1(Eg[i].V1), q = f1(Eg[i].V2);

		if (p == q)
		{
			nEg.push_back(Eg[i]);
			continue;
		}
		p > q ? P[p] = q : P[q] = p;
		s += Eg[i].W;
		Gr[Eg[i].V1].push_back({ Eg[i].V2, Eg[i].W });
		Gr[Eg[i].V2].push_back({ Eg[i].V1, Eg[i].W });
		An[{Eg[i].V1, Eg[i].V2}] = -1;
	}
}
void f3(int p, int q)
{
	D[p] = q;
	for (auto& a : Gr[p])
		if (!D[a.p])
		{
			dp[a.p][0] = p;
			C[a.p] = a.q;
			f3(a.p, q + 1);
		}
}
void f4()
{
	iota(P, P + N, 0);
	for (j = 1; j < 18; j++)
		for (i = 1; i <= n; i++)
			dp[i][j] = dp[dp[i][j - 1]][j - 1];
}
int f5(int p, int q)
{
	if (D[p] < D[q])
		swap(p, q);
	int d = D[p] - D[q];
	for (i = 0; d; d >>= 1, i++)
		if (d & 1)
			p = dp[p][i];
	if (p ^ q)
	{
		for (i = 17; i >= 0; i--)
			if (dp[p][i] ^ dp[q][i])
				p = dp[p][i], q = dp[q][i];
		p = dp[p][0];
	}
	return p;
}
void f6(int x, int y, int z)
{
	int t = D[x] < D[y] ? C[y] : C[x];
	if (x > y)
		swap(x, y);
	if (An[{x, y}] == -1)
		An[{x, y}] = s - t + z;
}
void f7()
{
	for (auto& a : nEg)
	{
		int p = f1(a.V1), q = f1(a.V2);
		int l = f1(f5(p, q));
		while (p ^ l)
		{
			i = dp[p][0], P[p] = l;
			f6(p, i, a.W);
			p = f1(i);
		}
		while (q ^ l)
		{
			i = dp[q][0], P[q] = l;
			f6(q, i, a.W);	
			q = f1(i);
		}
	}
}
int main()
{
	in(); f2();
	f3(1, 1); f4();
	f7();
	for (i = 0; i < m; i++)
		cout << (!An[{cEg[i].V1, cEg[i].V2}] ? s : An[{cEg[i].V1, cEg[i].V2}]) << '\n';
}
