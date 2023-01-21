#include<bits/stdc++.h>
#define N 100001
using namespace std;

vector <int> Gr[N];
int D[N], dp[N][18];
int n, i, j, o;

void in()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (; o < n - 1; o++)
		cin >> i >> j, Gr[i].push_back(j), Gr[j].push_back(i);
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
		for (o = 17; o >= 0; o--)
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
		cin >> i >> j, cout << f3(i, j) << '\n';
}
int main()
{
	in();
	f1(1, 1); f2();
	sv();
}
