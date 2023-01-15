#include <bits/stdc++.h>
#define N 500001
using namespace std;

struct S { int s, e, i; }Q[N];
int a[N], b[N], an[N], C[N];
int n, q, sn, i, s, e, t;

void in()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> q; sn = sqrt(n);
	for (i = 1; i <= n; cin >> a[i++]);
	for (i = 0; i < q; i++)
		cin >> Q[i].s >> Q[i].e, Q[i].i = i;
	memcpy(b, a, sizeof a);
}
void f()
{
	sort(b + 1, b + n + 1);
	sort(Q, Q + q, [](S p, S q)
		{
			p.s /= sn, q.s /= sn;
			return p.s ^ q.s ? p.s < q.s : p.e < q.e;
		});
	for (i = 1; i <= n; i++)
		a[i] = lower_bound(b, b + n + 1, a[i]) - b;
}
void sv()
{
	for (i = 0; i < q; i++)
	{
		while (s > Q[i].s)
		{
			C[a[--s]]++;
			if (C[a[s]] == 2)
				t++;
			else if (C[a[s]] == 3)
				t--;
		}
		while (s < Q[i].s)
		{
			if (C[a[s]] == 2)
				t--;
			else if (C[a[s]] == 3)
				t++;
			C[a[s++]]--;
		}
		while (e > Q[i].e)
		{
			if (C[a[e]] == 2)
				t--;
			else if (C[a[e]] == 3)
				t++;
			C[a[e--]]--;
		}
		while (e < Q[i].e)
		{
			C[a[++e]]++;
			if (C[a[e]] == 2)
				t++;
			else if (C[a[e]] == 3)
				t--;
		}
		an[Q[i].i] = t;
	}
	for (i = 0; i < q; cout << an[i++] << '\n');
}
int main()
{
	in();
	f();
	sv();
}
