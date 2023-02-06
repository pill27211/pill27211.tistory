#include<bits/stdc++.h>
#define N 100001
using namespace std;

struct _Q { int s, e, i; }Q[N];
long long t, an[N];
int seg[N], a[N];
int n, q, k, i, s, e, sn;

void in()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k; sn = sqrt(n);
	for (i = 1; i <= n; cin >> a[i++]);
	for (cin >> q, i = 0; i < q; i++)
		cin >> Q[i].s >> Q[i].e, Q[i].i = i;
}
void f1(int p, int q)
{
	while (p <= N - 1)
		seg[p] += q, p += p & -p;
}
int f2(int p)
{
	if (p < 0) p = 0;
	if (p >= N) p = N - 1;
	int r{};
	while (p)
		r += seg[p], p -= p & -p;
	return r;
}
int f3(int p) { return f2(a[p] + k) - f2(a[p] - k - 1); }
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
		while (s > Q[i].s) t += f3(--s), f1(a[s], 1);
		while (s < Q[i].s) f1(a[s], -1), t -= f3(s++);
		while (e > Q[i].e) f1(a[e], -1), t -= f3(e--);
		while (e < Q[i].e) t += f3(++e), f1(a[e], 1);
		an[Q[i].i] = t;
	}
	for (i = 0; i < q; cout << an[i++] << '\n');
}
int main()
{
	in();
	sv();
}
