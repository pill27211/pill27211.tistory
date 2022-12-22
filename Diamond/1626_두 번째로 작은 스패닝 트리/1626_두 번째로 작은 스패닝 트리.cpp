#include<bits/stdc++.h>
#define ll long long
#define N 50001
using namespace std;

struct S { int p, q; };
struct E
{
	int v1, v2, w;
	bool operator<(E& e) { return w < e.w; }
}Eg[200001];

vector <E> V;
vector <S> Gr[N];
int dp[N][17], mdp[N][17], sdp[N][17];
int P[N], D[N];
int n, m, i, j, s, o;

void f0()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	iota(P, P + N, 0);
	for (i = 0; i < m; i++)
		cin >> Eg[i].v1 >> Eg[i].v2 >> Eg[i].w;
}
int f1(int p)
{
	return P[p] = P[p] == p ? p : f1(P[p]);
}
void f2()
{
	sort(Eg, Eg + m);
	for (i = 0; i < m; i++)
	{
		int p = f1(Eg[i].v1), q = f1(Eg[i].v2);

		if (p == q)
		{
			V.push_back(Eg[i]);
			continue;
		}
		s += Eg[i].w; o++;
		Gr[Eg[i].v1].push_back({ Eg[i].v2, Eg[i].w });
		Gr[Eg[i].v2].push_back({ Eg[i].v1, Eg[i].w });
		p > q ? P[p] = q : P[q] = p;
	}
}
void f3(int x, int d)
{
	D[x] = d;
	for (auto& a : Gr[x])
		if (!D[a.p])
		{
			mdp[a.p][0] = a.q, sdp[a.p][0] = -1;
			dp[a.p][0] = x;
			f3(a.p, d + 1);
		}
}
void f4()
{
	for (j = 1; j < 17; j++)
		for (i = 1; i <= n; i++)
		{
			dp[i][j] = dp[dp[i][j - 1]][j - 1];
			mdp[i][j] = max(mdp[i][j - 1], mdp[dp[i][j - 1]][j - 1]);

			int p = max(mdp[i][j - 1] == mdp[i][j] ? -1 : mdp[i][j - 1], mdp[dp[i][j - 1]][j - 1] == mdp[i][j] ? -1 : mdp[dp[i][j - 1]][j - 1]);
			int q = max(sdp[i][j - 1] == mdp[i][j] ? -1 : sdp[i][j - 1], sdp[dp[i][j - 1]][j - 1] == mdp[i][j] ? -1 : sdp[dp[i][j - 1]][j - 1]);
			sdp[i][j] = max(p, q);
		}
}
int f5(int p, int q, int z)
{
	if (D[p] < D[q])
		swap(p, q);
	int g = -1, d = D[p] - D[q];

	for (j = 0; d; d >>= 1, j++)
		if (d & 1)
			g = max(g, mdp[p][j] ^ z ? mdp[p][j] : sdp[p][j]), p = dp[p][j];
	if (p == q)
		return g;
	for (j = 16; j >= 0; j--)
		if (dp[p][j] ^ dp[q][j])
		{
			g = max(g, mdp[p][j] ^ z ? mdp[p][j] : sdp[p][j]);
			g = max(g, mdp[q][j] ^ z ? mdp[q][j] : sdp[q][j]);
			p = dp[p][j], q = dp[q][j];
		}
	g = max(g, mdp[p][0] ^ z ? mdp[p][0] : sdp[p][0]);
	g = max(g, mdp[q][0] ^ z ? mdp[q][0] : sdp[q][0]);
	return g;
}
void f6()
{
	ll r = 1e12;
	if (o ^ n - 1)
		cout << -1, exit(0);
	for (i = (int)V.size() - 1; i >= 0; i--)
	{
		n = f5(V[i].v1, V[i].v2, V[i].w);
		if (n ^ -1)
		{
			ll k = (ll)s - n + V[i].w;
			if (k > s && k < r)
				r = k;
		}
	}
	cout << (r ^ (ll)1e12 ? r : -1);
}
int main()
{
	f0();
	f2();
	f3(1, 1);
	f4();
	f6();
}
