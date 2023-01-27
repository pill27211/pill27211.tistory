#include <bits/stdc++.h>
#define N 100001
using namespace std;

struct _Q { int s, e, i, k; }Q[N];
vector <int> Gr[N];
int in[N], out[N], rec[N * 2], dp[N][18];
int D[N], W[N], NC[N], WC[N * 10], an[N];
int n, q, o, i, j, ri;
int sn, s, e, t;

void in1()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n; sn = sqrt(n);
	for (i = 1; i <= n; cin >> W[i++]);
	for (q = 1; q < n; q++)
		cin >> i >> j, Gr[j].push_back(i), Gr[i].push_back(j);
}
void f1(int p, int q)
{
	D[p] = q, in[p] = ++o, rec[++ri] = p;
	for (int& i : Gr[p])
		if (!D[i])
			dp[i][0] = p, f1(i, q + 1);
	out[p] = ++o, rec[++ri] = p;
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
	int d = D[p] - D[q], o{};
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
void f4(int p, int q)
{
	int x(W[p]); NC[p] += q;
	if (NC[p] == 1)
		WC[x]++, t += WC[x] == 1;
	if(NC[p] == (q > 0 ? 2 : 0))
		WC[x]--, t -= !WC[x];
}
void in2()
{
	cin >> q;
	for (o = 0; o < q; o++)
	{
		cin >> Q[o].s >> Q[o].e, Q[o].i = o;
		_Q& i(Q[o]);
		if (in[i.s] > in[i.e]) swap(i.s, i.e);
		j = f3(i.s, i.e); i.e = in[i.e];
		i.s == j ? i.s = in[i.s] : (i.s = out[i.s], i.k = in[j]);
	}
	sort(Q, Q + q, [](_Q p, _Q q)
		{
			p.s /= sn, q.s /= sn;
			return p.s ^ q.s ? p.s < q.s : p.e < q.e;
		});
}
void sv()
{
	for (i = 0; i < q; i++)
	{
		while (s > Q[i].s) f4(rec[--s], 1);
		while (s < Q[i].s) f4(rec[s++], -1);
		while (e > Q[i].e) f4(rec[e--], -1);
		while (e < Q[i].e) f4(rec[++e], 1);
		if (Q[i].k) f4(rec[Q[i].k], 1);
		an[Q[i].i] = t;
		if (Q[i].k) f4(rec[Q[i].k], -1);
	}
	for (i = 0; i < q; cout << an[i++] << '\n');
}
int main()
{
	in1();
	f1(1, 1); f2();
	in2();
	sv();
}
