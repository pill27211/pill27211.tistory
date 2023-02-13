#include<bits/stdc++.h>
#define ll long long
#define N 200001
using namespace std;

struct S
{
	ll p, q;
	double d;
	bool operator<(ll x) { return d < x; }
}ln[N];
ll n, u, i, s, r, a[N], p[N];

inline double f(S& l, S& r) { return (r.q - l.q) / (l.p - r.p); }
ll Q(S t, ll x)
{
	while (u > 1 && f(ln[u - 2], t) > f(ln[u - 1], t)) u--;
	if (u) ln[u - 1].d = f(ln[u - 1], t);
	ln[u++] = t;
	return lower_bound(ln, ln + u - 1, x) - ln;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (i = 1; i <= n; i++)
		cin >> a[i], p[i] = a[i] + p[i - 1], s += i * a[i];
	for (i = 1; i <= n; i++)
	{
		ll j = Q({ i, -p[i - 1], 0 }, a[i]);
		r = max(r, ln[j].p * a[i] + ln[j].q + p[i - 1] - i * a[i]);
	}
	for (u = 0, i = n; i; i--)
	{
		ll j = Q({ -i, -p[i], 0 }, -a[i]);
		r = max(r, -ln[j].p * a[i] + ln[j].q + p[i] - i * a[i]);
	}
	cout << s + r;
}
