#include<bits/stdc++.h>
#define ll long long
#define N 1000001
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
ll n, i, M(1e18), a[N], dp[N];

void push(L q, ll n)
{
	ll s(T[n].s), e(T[n].e), m((s + e) >> 1); L p = T[n].ln;
	if (p.f(s) > q.f(s)) swap(p, q);
	if (p.f(e) <= q.f(e)) { T[n].ln = p; return; }
	if (p.f(m) < q.f(m))
	{
		T[n].ln = p;
		if (!~T[n].r)
			T[n].r = T.size(), T.push_back({ -1, -1, m + 1, e, { 0, M } });
		push(q, T[n].r);
		return;
	}
	T[n].ln = q;
	if (!~T[n].l)
		T[n].l = T.size(), T.push_back({ -1, -1, s, m, { 0, M } });
	push(p, T[n].l);
}
ll Q(ll x, ll n){ return !~n ? M : min(T[n].ln.f(x), Q(x, ((x << 1) <= T[n].s + T[n].e ? T[n].l : T[n].r))); }
void sv()
{
	T.push_back({ -1, -1, 0, (ll)1e12, {0, M} });
	for (i = n - 1; !!~i; i--)
		push({ -a[i + 1], (i + 1) * a[i + 1] + dp[i + 1] }, 0), dp[i] = Q(i, 0);
	cout << dp[0];
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (cin >> n, i = 1; i <= n; cin >> a[i++]);
	sv();
}
