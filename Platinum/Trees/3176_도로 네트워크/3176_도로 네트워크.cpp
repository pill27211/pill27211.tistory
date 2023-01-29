#include<bits/stdc++.h>
#define P pair<int, int>
#define F first
#define S second
#define N 100001
using namespace std;

vector <P> Gr[N];
int D[N], dp[N][18];
int mdp[N][18], Mdp[N][18];
int n, q, i, j;

void in()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int o{1}; o < n; o++)
		cin >> i >> j >> q, Gr[i].emplace_back(j, q), Gr[j].emplace_back(i, q);
}
void f1(int p, int q)
{
	D[p] = q;
	for (auto& i : Gr[p])
		if (!D[i.F])
			dp[i.F][0] = p, Mdp[i.F][0] = mdp[i.F][0] = i.S, f1(i.F, q + 1);
}
void f2()
{
	for (j = 1; j < 18; j++)
		for (i = 1; i <= n; i++)
		{
			dp[i][j] = dp[dp[i][j - 1]][j - 1];
			Mdp[i][j] = max(Mdp[i][j - 1], Mdp[dp[i][j - 1]][j - 1]);
			mdp[i][j] = min(mdp[i][j - 1], mdp[dp[i][j - 1]][j - 1]);
		}
}
P f3(int p, int q)
{
	if (D[p] < D[q])
		swap(p, q);
	P r({2e9, -2e9});
	n = D[p] - D[q];
	for (int k{}; n; n >>= 1, k++)
		if (n & 1)
		{
			r.F = min(r.F, mdp[p][k]);
			r.S = max(r.S, Mdp[p][k]);
			p = dp[p][k];
		}
	if(p ^ q)
	{
		for(int k{17}; k >= 0; k--)
			if (dp[p][k] ^ dp[q][k])
			{
				r.F = min({r.F, mdp[p][k], mdp[q][k]});
				r.S = max({r.S, Mdp[p][k], Mdp[q][k]});
				p = dp[p][k], q = dp[q][k];
			}
		r.F = min({r.F, mdp[p][0], mdp[q][0]});
		r.S = max({r.S, Mdp[p][0], Mdp[q][0]});
	}
	return r;
}
void sv()
{
	cin >> q;
	while (q--)
	{
		cin >> i >> j;
		P p(f3(i, j));
		cout << p.F << ' ' << p.S << '\n';
	}
}
int main(void)
{
	in();
	f1(1, 1), f2();
	sv();
}
