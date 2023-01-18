#include <bits/stdc++.h>
#define N 100001
using namespace std;

vector <int> Gr[N];
int dp[N][18], mdp[N][18];
int D[N], C[N], V[6];
int n, q, i, j, o;

void in()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (i = 1; i <= n; i++)
		cin >> C[i], V[C[i]] = 1;
	for (; o < n - 1; o++)
		cin >> i >> j, Gr[i].push_back(j), Gr[j].push_back(i);
}
void f1(int p, int q)
{
	D[p] = q;
	for (int i : Gr[p])
		if (!D[i])
			dp[i][0] = p, mdp[i][0] = (1 << C[p]), f1(i, q + 1);
}
void f2()
{
	for (j = 1; j < 18; j++)
		for (i = 1; i <= n; i++)
			dp[i][j] = dp[dp[i][j - 1]][j - 1], mdp[i][j] = (mdp[i][j - 1] | mdp[dp[i][j - 1]][j - 1]);
}
int f3(int p, int q)
{
	if (D[p] < D[q]) swap(p, q);
	int d = D[p] - D[q], g{ (1 << C[p]) | (1 << C[q]) };
	for (int i = 0; d; d >>= 1, i++)
		if (d & 1)
			g |= mdp[p][i], p = dp[p][i];
	if (p ^ q)
	{
		for (int i = 17; i >= 0; i--)
			if (dp[p][i] ^ dp[q][i])
			{
				g |= (mdp[p][i] | mdp[q][i]);
				p = dp[p][i], q = dp[q][i];
			}
		g |= (mdp[p][0] | mdp[q][0]);
	}
	return g;
}
void sv()
{
	cin >> q >> i >> j;
	q--; o = i;
	cout << (V[j] ? "PLAY" : "CRY") << '\n';
	while (q--)
	{
		cin >> i >> j;
		int l = f3(o, i);
		cout << (l & (1 << j) ? "PLAY" : "CRY") << '\n';
		o = i;
	}
}
int main()
{
	in();
	f1(1, 1); f2();
	sv();
}
