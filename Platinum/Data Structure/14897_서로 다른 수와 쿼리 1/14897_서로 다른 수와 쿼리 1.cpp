#include<bits/stdc++.h>
#define N 1000001
using namespace std;

struct _Q { int s, e, i; }Q[N], a[N];
int r[N], c[N];
int n, sn, q, i, j;
int s, e, t;

void in()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (i = 1; i <= n; i++)
		cin >> a[i].e, a[i].i = i;
	cin >> q;
	for (i = 0; i < q; i++)
		cin >> Q[i].s >> Q[i].e, Q[i].i = i;
}
void f1()
{
	sort(a + 1, a + n + 1, [](_Q& p, _Q& q) {return p.e < q.e; });
	for (a[1].s = 1, sn = i = 2; i <= n; i++)
		a[i].s = a[i].e == a[i - 1].e ? a[i - 1].s : sn++;
	sort(a + 1, a + n + 1, [](_Q& p, _Q& q) {return p.i < q.i; });
	sn = sqrt(n);
	sort(Q, Q + q, [](_Q p, _Q q)
	{
		p.s /= sn, q.s /= sn;
		return p.s ^ q.s ? p.s < q.s : p.e < q.e;
	});
}
void f2()
{
	for (s = i = Q[0].s, e = Q[0].e; i <= e; i++)
	{
		c[a[i].s]++;
		t += c[a[i].s] == 1;
	}
	r[Q[0].i] = t;
	for (i = 1; i < q; i++)
	{
		while (s > Q[i].s)
		{
			s--;
			c[a[s].s]++;
			t += c[a[s].s] == 1;
		}
		while (s < Q[i].s)
		{
			c[a[s].s]--;
			t -= c[a[s].s] == 0;
			s++;
		}
		while (e > Q[i].e)
		{
			c[a[e].s]--;
			t -= c[a[e].s] == 0;
			e--;
		}
		while (e < Q[i].e)
		{
			e++;
			c[a[e].s]++;
			t += c[a[e].s] == 1;
		}
		r[Q[i].i] = t;
	}
}
int main()
{
	in();
	f1();
	f2();
	for (i = 0; i < q; cout << r[i++] << '\n');
}