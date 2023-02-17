#include<bits/stdc++.h>
#define ll long long
#define N 200001
using namespace std;

vector <int> Gr[N];
int D[N], dp[N][19];
ll n, i, j, d, r;

void f1(int p, int q)
{
	D[p] = q;
	for (int& a : Gr[p])
		if (!D[a])
			dp[a][0] = p, f1(a, q + 1);
}
void f2()
{
	for (j = 1; j < 19; j++)
		for (i = 1; i <= n; i++)
			dp[i][j] = dp[dp[i][j - 1]][j - 1];
}
ll f3(int p, int q)
{
	if (D[p] < D[q]) swap(p, q);
	d = D[p] - D[q];
	for (int k = 0; d; d >>= 1, k++)
		if (d & 1)
			p = dp[p][k];
	if(p ^ q)
	{
		for (int k = 18; k >= 0; k--)
			if (dp[p][k] ^ dp[q][k])
				p = dp[p][k], q = dp[q][k];
		p = dp[p][0];
	}
	return (D[i] - D[p]) + (D[j] - D[p]) + 1;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (i = 1; i < n; i++)
		cin >> j >> d, Gr[j].push_back(d), Gr[d].push_back(j);
	f1(1, 1); f2();
	for (i = 1; i <= n / 2; i++)
		for (j = i + i; j <= n; j += i)
			r += f3(j, i);
	cout << r;
}
