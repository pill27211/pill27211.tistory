#include<bits/stdc++.h>
#define N 40001
using namespace std;

vector <pair<int, int>> Gr[N];
int D[N], W[N], dp[N][17];
int n, i, j, w, o;

void in()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (; o < n - 1; o++)
		cin >> i >> j >> w, Gr[i].emplace_back(j, w), Gr[j].emplace_back(i, w);
}
void f1(int p, int q)
{
	D[p] = q;
	for (auto& i : Gr[p])
		if (!D[i.first])
			dp[i.first][0] = p, W[i.first] = W[p] + i.second, f1(i.first, q + 1);
}
void f2()
{
	for (j = 1; j < 17; j++)
		for (i = 1; i <= n; i++)
			dp[i][j] = dp[dp[i][j - 1]][j - 1];
}
int f3(int p, int q)
{
	if (D[p] < D[q]) swap(p, q);
	int d = D[p] - D[q];
	for (o = 0; d; d >>= 1, o++)
		if (d & 1)
			p = dp[p][o];
	if (p ^ q)
	{
		for (o = 16; o >= 0; o--)
			if (dp[p][o] ^ dp[q][o])
				p = dp[p][o], q = dp[q][o];
		p = dp[p][0];
	}
	return p;
}
void sv()
{
	cin >> n;
	while (n--)
		cin >> i >> j, cout << W[i] + W[j] - 2 * W[f3(i, j)] << '\n';
}
int main()
{
	in();
	f1(1, 1); f2();
	sv();
}
