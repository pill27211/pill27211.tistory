#include<bits/stdc++.h>
#define ll long long
#define N 100001
using namespace std;

struct _Q { int s, e, i; }Q[N];
int n, q, i, a[N], c[N * 10];
ll s, e, t, sn, an[N];

ll f(int p) { return (ll)c[a[p]] * c[a[p]] * a[p]; }
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> q; sn = sqrt(n);
	for (i = 1; i <= n; cin >> a[i++]);
	for (i = 0; i < q; i++)
		cin >> Q[i].s >> Q[i].e, Q[i].i = i;
	sort(Q, Q + q, [](_Q x, _Q y)
		{
			x.s /= sn, y.s /= sn;
			return x.s ^ y.s ? x.s < y.s : x.e < y.e;
		});
	for (i = 0; i < q; i++)
	{
		while (s > Q[i].s) t -= f(--s), c[a[s]]++, t += f(s);
		while (s < Q[i].s) t -= f(s), c[a[s]]--, t += f(s++);
		while (e > Q[i].e) t -= f(e), c[a[e]]--, t += f(e--);
		while (e < Q[i].e) t -= f(++e), c[a[e]]++, t += f(e);
		an[Q[i].i] = t;
	}
	for (i = 0; i < q; cout << an[i++] << '\n');
}
