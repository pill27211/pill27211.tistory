#include <bits/stdc++.h>
#define ll long long
#define N 200001
using namespace std;

vector <int> Gr[N];
int D[N], dp[N][19];
int n, q, i, j, o;
ll r, S[N], Sdp[N];

void in()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> q;
	for (; o < n - 1; o++)
		cin >> i >> j, Gr[i].push_back(j), Gr[j].push_back(i);
}
void f1(int p, int q)
{
	D[p] = q; S[p] = 1;
	for (int i : Gr[p])
		if (!D[i])
		{
			f1(i, q + 1);
			Sdp[p] += S[i] * (S[p] - 1);
			dp[i][0] = p, S[p] += S[i];
		}
}
void f2()
{
	for (j = 1; j < 19; j++)
		for (i = 1; i <= n; i++)
			dp[i][j] = dp[dp[i][j - 1]][j - 1];
}
int f3(int p, int q, int k)
{
	if (D[p] < D[q]) swap(p, q);
	int d(D[p] - D[q] - k);
	for (int i{}; d; d >>= 1, i++)
		if (d & 1)
			p = dp[p][i];
	if (!k && p ^ q)
	{
		for (int i(18); i >= 0; i--)
			if (dp[p][i] ^ dp[q][i])
				p = dp[p][i], q = dp[q][i];
		p = dp[p][0];
	}
	return p;
}
void sv()
{
	for (o = 1; q--;)
		if (cin >> i >> j, i & 1) o = j;
		else
		{
			if (j == o)
				r = -S[j] * (S[j] - n - 1);
			else if (j == f3(j, o, 0))
			{
				i = f3(j, o, 1);
				r = S[i] * (S[i] - n) - S[j] * (S[j] - n - 1);
			}
			else
				r = S[j];
			cout << r + Sdp[j] - 1 << '\n';
		}
}
int main()
{
	in();
	f1(1, 1);
	f2();
	sv();
}
