#include<bits/stdc++.h>
#define ll long long
#define N 100001
using namespace std;

vector <int> Gr[N];
int D[N], dp[N][18];
int n, m, q, t, i, j, o;
ll S[N];

void in()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> t;
	for (i = 0; i < n - 1; i++)
		for (j = 1; j <= m; j++)
			if (cin >> o, !o)
			{
				int y(i * m + j), x(y + m);
				Gr[y].push_back(x), Gr[x].push_back(y);
			}
	for (i = 0; i < n; i++)
		for (j = 1; j < m; j++)
			if (cin >> o, !o)
			{
				int y(i * m + j), x(y + 1);
				Gr[y].push_back(x), Gr[x].push_back(y);
			}
}
void f1(int p, int q)
{
	D[p] = q;
	for (int i : Gr[p])
		if (!D[i])
			dp[i][0] = p, f1(i, q + 1);
}
void f2()
{
	for (j = 1; j < 18; j++)
		for (i = 1; i <= n * m; i++)
			dp[i][j] = dp[dp[i][j - 1]][j - 1];
}
int f3(int p, int q)
{
	if (D[p] < D[q]) swap(p, q);
	int d(D[p] - D[q]);
	for (int i{}; d; d >>= 1, i++)
		if (d & 1)
			p = dp[p][i];
	if (p ^ q)
	{
		for (int i(17); i >= 0; i--)
			if (dp[p][i] ^ dp[q][i])
				p = dp[p][i], q = dp[q][i];
		p = dp[p][0];
	}
	return p;
}
void sv()
{
	cin >> q;
	while (q--)
	{
		ll s, e, y, x, v;
		cin >> s >> e >> i >> j >> y >> x >> v;
		i = i * m + j + 1;
		j = y * m + x + 1;
		x = (D[i] + D[j] - 2 * D[f3(i, j)] + 1) * v;
		S[s] += x, S[e + 1] -= x;
	}
	for (i = 1; i <= t; i++)
		S[i] += S[i - 1], cout << S[i] << '\n';
}
int main()
{
	in();
	f1(1, 1);
	f2();
	sv();
}
