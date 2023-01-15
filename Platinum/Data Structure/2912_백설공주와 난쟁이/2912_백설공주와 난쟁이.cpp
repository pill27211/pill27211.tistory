#include<bits/stdc++.h>
#define N 10001
using namespace std;

struct S { int s, e, i; }Q[N];
int a[N * 30], an[N], C[N];
int n, c, q, sn, i, s, e;

void in()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> c; sn = sqrt(n);
	for (i = 1; i <= n; cin >> a[i++]);
	cin >> q;
	for (i = 0; i < q; i++)
		cin >> Q[i].s >> Q[i].e, Q[i].i = i;
	sort(Q, Q + q, [](S p, S q)
		{
			p.s /= sn, q.s /= sn;
			return p.s ^ q.s ? p.s < q.s : p.e < q.e;
		});
}
void sv()
{
	for (i = 0; i < q; i++)
	{
		while (s > Q[i].s) C[a[--s]]++;
		while (s < Q[i].s) C[a[s++]]--;
		while (e > Q[i].e) C[a[e--]]--;
		while (e < Q[i].e) C[a[++e]]++;
		an[Q[i].i] = find_if(C, C + N, [](int p) {return p * 2 > e - s + 1; }) - C;
	}
	for (i = 0; i < q; i++)
		an[i] == N ? cout << "no\n" : cout << "yes " << an[i] << '\n';
}
int main()
{
	in();
	sv();
}
