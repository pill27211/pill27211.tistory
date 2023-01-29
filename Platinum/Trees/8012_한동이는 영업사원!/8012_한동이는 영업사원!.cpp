#include<bits/stdc++.h>
#define N 30001
using namespace std;

vector <int> Gr[N];
int D[N], dp[N][16];
int n, m, i, j, r;

void in()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (i = 1; i < n; i++)
		cin >> m >> j, Gr[m].push_back(j), Gr[j].push_back(m);
}
void f1(int p, int q)
{
	D[p] = q;
	for (int& i : Gr[p])
		if (!D[i])
			dp[i][0] = p, f1(i, q + 1);
}
void f2()
{
	for (j = 1; j < 16; j++)
		for (i = 1; i <= n; i++)
			dp[i][j] = dp[dp[i][j - 1]][j - 1];
}
int f3(int p, int q)
{
	if (D[p] < D[q])
		swap(p, q);
	n = D[p] - D[q];
	for (int k = 0; n; n >>= 1, k++)
		if (n & 1)
			p = dp[p][k];
	if(p ^ q)
	{
		for(int k = 15; k >= 0; k--)
			if (dp[p][k] ^ dp[q][k])
				p = dp[p][k], q = dp[q][k];
		p = dp[p][0];
	}
	return D[i] + D[j] - 2 * D[p];
}
void sv()
{
	cin >> m >> i;
	r += D[i], m--;
	while (m--)
	{
		cin >> j;
		r += f3(i, j);
		i = j;
	}
	cout << r - 1;
}
int main(void)
{
	in();
	f1(1, 1), f2();
	sv();
}
