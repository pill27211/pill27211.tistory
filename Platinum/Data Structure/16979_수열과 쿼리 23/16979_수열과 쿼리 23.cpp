#include<bits/stdc++.h>
#define N 100001
using namespace std;

struct S {int s, e, i;}Q[N];
int a[N], b[N], seg[N];
long long t, an[N];
int n, sn, q, i, s, e;

void in()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> q; sn = sqrt(n);
	for (i = 1; i <= n; i++)
		cin >> a[i], b[i] = a[i];
	for (i = 0; i < q; i++)
		cin >> Q[i].s >> Q[i].e, Q[i].i = i;
}
void f0()
{
	sort(b, b + n + 1);
	for (i = 1; i <= n; i++)
		a[i] = lower_bound(b, b + n + 1, a[i]) - b;
	sort(Q, Q + q, [](S p, S q)
		{
			p.s /= sn, q.s /= sn;
			return p.s ^ q.s ? p.s < q.s : p.e < q.e;
		});
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
	s = Q[0].s, e = s - 1;
	for (i = 0; i < q; i++)
	{
		while (s > Q[i].s)
			t += f2(a[--s] - 1), f1(a[s], 1);
		while (s < Q[i].s)
			f1(a[s], -1), t -= f2(a[s++] - 1);
		while (e > Q[i].e)
			f1(a[e], -1), t -= f2(N - 1) - f2(a[e--]);
		while (e < Q[i].e)
			t += f2(N - 1) - f2(a[++e]), f1(a[e], 1);
		an[Q[i].i] = t;
	}
	for (i = 0; i < q; cout << an[i++] << '\n');
}
int main()
{
	in();
	f0();
	sv();
}
