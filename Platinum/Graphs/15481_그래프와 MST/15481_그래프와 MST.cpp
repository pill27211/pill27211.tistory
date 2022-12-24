#include<bits/stdc++.h>
#define ll long long
#define N 200001
using namespace std;

typedef struct _Edge
{
	int V1;
	int V2;
	ll W;

	bool operator<(struct _Edge& e) { return W < e.W; }
}Edge;

vector <Edge> Eg(N), CV(N);
vector <pair<int, ll>> Gr[N];
int P[N];
int D[N], dp[N][19];
int Mdp[N][19];
int n, m, i, j;
ll w, s;

void f0()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	iota(P, P + N, 0);
	for (i = 0; i < m; i++)
		cin >> Eg[i].V1 >> Eg[i].V2 >> Eg[i].W;
}
int f1(int p)
{
	return P[p] = P[p] == p ? p : f1(P[p]);
}
void f3()
{
	CV = Eg;
	sort(CV.begin(), CV.begin() + m);

	for (i = 0; i < m; i++)
	{
		int o1 = f1(CV[i].V1);
		int o2 = f1(CV[i].V2);

		if (o1 ^ o2)
		{
			s += CV[i].W;
			o1 > o2 ? P[o1] = o2 : P[o2] = o1;
			Gr[CV[i].V1].push_back({ CV[i].V2, CV[i].W });
			Gr[CV[i].V2].push_back({ CV[i].V1, CV[i].W });
		}
	}
}
void f4(int p, int q)
{
	D[p] = q;
	for (auto& a : Gr[p])
		if (!D[a.first])
			dp[a.first][0] = p, Mdp[a.first][0] = a.second, f4(a.first, q + 1);
}
void f5()
{
	for (j = 1; j < 19; j++)
		for (i = 1; i <= n; i++)
		{
			dp[i][j] = dp[dp[i][j - 1]][j - 1];
			Mdp[i][j] = max(Mdp[i][j - 1], Mdp[dp[i][j - 1]][j - 1]);
		}
}
int f6(int p, int q)
{
	if (D[p] < D[q])
		swap(p, q);
	int g = 0, d = D[p] - D[q];

	for (int k = 0; d; d >>= 1, k++)
		if (d & 1)
			g = max(g, Mdp[p][k]), p = dp[p][k];
	if (p == q)
		return g;
	for (int k = 18; k >= 0; k--)
		if (dp[p][k] != dp[q][k])
		{
			g = max(g, max(Mdp[p][k], Mdp[q][k]));
			p = dp[p][k];
			q = dp[q][k];
		}
	g = max(g, max(Mdp[p][0], Mdp[q][0]));
	return g;
}
void f7()
{
	for (n = 0; n < m; n++)
	{
		i = Eg[n].V1;
		j = Eg[n].V2;
		w = Eg[n].W;

		cout << s - f6(i, j) + w << '\n';
	}
}
int main()
{
	f0();
	f3();
	f4(1, 1);
	f5();
	f7();
}
