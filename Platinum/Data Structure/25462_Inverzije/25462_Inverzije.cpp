#include<bits/stdc++.h>
#define N 100001
using namespace std;

struct _Q { int s, e, i; }Q[N];
long long t, an[N];
int seg[N], c[N];
int n, q, i, s, e, sn;

void in()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> q; sn = sqrt(n);
	for (i = 1; i <= n; cin >> c[i++]);
	for (int i = 0; i < q; i++)
		cin >> Q[i].s >> Q[i].e, Q[i].i = i;
}
void f1(int p, int q)
{
	while (p <= N - 1)
		seg[p] += q, p += p & -p;
}
int f2(int p)
{
	int r{};
	while (p)
		r += seg[p], p -= p & -p;
	return r;
}
void sv()
{
	sort(Q, Q + q, [](_Q x, _Q y)
		{
			x.s /= sn, y.s /= sn;
			return x.s ^ y.s ? x.s < y.s : x.e < y.e;
		});
	s = Q[0].s, e = s - 1;
	for (i = 0; i < q; i++)
	{
		while (s > Q[i].s) t += f2(c[--s] - 1), f1(c[s], 1);
		while (s < Q[i].s) t -= f2(c[s] - 1), f1(c[s++], -1);
		while (e > Q[i].e) t -= f2(N - 1) - f2(c[e]), f1(c[e--], -1);
		while (e < Q[i].e) t += f2(N - 1) - f2(c[++e]), f1(c[e], 1);
		an[Q[i].i] = t;
	}
	for (i = 0; i < q; cout << an[i++] << '\n');
}
int main()
{
	in();
	sv();
}
