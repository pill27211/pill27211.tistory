#include<bits/stdc++.h>
#define N 30001
using namespace std;

struct S { int s, e, i = 1e9; }Q[N], seg[1 << 16];
int n, q, i, a[N], an[N];
int s, e, t;

S f1(int n, int s, int e, int p, int q)
{
	if (s > p || e < p) return seg[n];
	if (s == e) return seg[n] = { q, q, (int)1e9 };
	int m((s + e) >> 1);
	S L(f1(n << 1, s, m, p, q)), R(f1(n << 1 | 1, m + 1, e, p, q));
	seg[n] = { L.s, R.e, min({L.i, R.i, L.e && R.s ? R.s - L.e : (int)1e9}) };
	if (!seg[n].s) seg[n].s = R.s;
	if (!seg[n].e) seg[n].e = L.e;
	return seg[n];
}
void in()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> q;
	for (i = 1; i <= n; cin >> a[i++]);
	for (i = 0; i < q; i++)
		cin >> Q[i].s >> Q[i].e, Q[i].i = i;
}
void sv()
{
	sort(Q, Q + q, [](S x, S y)
		{
			x.s /= 300, y.s /= 300;
			return x.s ^ y.s ? x.s < y.s : x.e < y.e;
		});
	for (i = 0; i < q; i++)
	{
		while (s > Q[i].s) s--, f1(1, 1, n, a[s], a[s]);
		while (e < Q[i].e) e++, f1(1, 1, n, a[e], a[e]);
		while (s < Q[i].s) f1(1, 1, n, a[s], 0), s++;
		while (e > Q[i].e) f1(1, 1, n, a[e], 0), e--;
		an[Q[i].i] = seg[1].i;
	}
	for (i = 0; i < q; cout << an[i++] << '\n');
}
int main()
{
	in();
	sv();
}
