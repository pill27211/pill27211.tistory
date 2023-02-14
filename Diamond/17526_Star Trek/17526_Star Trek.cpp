#include<bits/stdc++.h>
#define ll long long
#define N 100001
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
ll M(1e18), c[N], dp[N];
int n, i, a[N], b[N];

void in()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (i = 2; i <= n; i++)
		cin >> c[i], c[i] += c[i - 1];
	for (i = 1; i < n; i++)
		cin >> a[i] >> b[i];
}
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
ll Q(ll x, ll n)
{
	if (!~n) return M;
	return min(T[n].ln.f(x), Q(x, ((x << 1) <= T[n].s + T[n].e ? T[n].l : T[n].r)));
}
void sv()
{
	T.push_back({ -1, -1, 0, (ll)1e9, {0, M} });
	for (i = 2; i <= n; i++)
		push({ b[i - 1], dp[i - 1] + a[i - 1] - b[i - 1] * c[i - 1] }, 0), dp[i] = Q(c[i], 0);
	cout << dp[n];
}
int main()
{
	in();
	sv();
}
