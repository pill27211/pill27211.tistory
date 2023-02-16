#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct L
{
	ll p, q;
	inline ll f(ll x) { return p * x + q; }
};
struct Node
{
	ll l, r, s, e;
	L ln;
};
vector <Node> T;
ll q, o, i, j, M(-2e18);

void push(L q, ll n)
{
	ll s(T[n].s), e(T[n].e), m((s + e) >> 1); L p = T[n].ln;
	if (p.f(s) > q.f(s)) swap(p, q);
	if (p.f(e) <= q.f(e)) { T[n].ln = q; return; }
	if (p.f(m) < q.f(m))
	{
		T[n].ln = q;
		if (!~T[n].r)
			T[n].r = T.size(), T.push_back({ -1, -1, m + 1, e, { 0, M } });
		push(p, T[n].r);
		return;
	}
	T[n].ln = p;
	if (!~T[n].l)
		T[n].l = T.size(), T.push_back({ -1, -1, s, m, { 0, M } });
	push(q, T[n].l);
}
ll Q(ll x, ll n){ return !~n ? M : max(T[n].ln.f(x), Q(x, ((x << 1) <= T[n].s + T[n].e ? T[n].l : T[n].r))); }
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	T.push_back({ -1, -1, (ll)-1e12, (ll)1e12, {0, M} });
	cin >> q;
	while (q--)
	{
		cin >> o;
		if (o & 1) cin >> i >> j, push({ i, j }, 0);
		else cin >> i, cout << Q(i, 0) << '\n';
	}
}
