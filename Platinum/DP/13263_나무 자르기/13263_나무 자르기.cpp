#include<bits/stdc++.h>
#define ll long long
#define N 100000
using namespace std;

struct S
{
	ll p, q;
	double d;
	bool operator<(int x) { return d < x; }
}ln[N];
ll n, u, i, a[N], b[N], dp[N];

inline double f(S& l, S& r) { return (r.q - l.q) / (l.p - r.p); }
void sv()
{
	for (i = 1; i < n; i++)
	{
		S t({ b[i - 1], dp[i - 1], 0 });
		while (u)
		{
			t.d = f(ln[u - 1], t);
			if (ln[u - 1].d < t.d) break;
			u--;
		}
		ln[u++] = t;
		ll x = a[i], j = u - 1;
		if (x < ln[u - 1].d)
			j = lower_bound(ln, ln + u, x) - ln - 1;
		dp[i] = ln[j].p * x + ln[j].q;
	}
	cout << dp[n - 1];
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (cin >> n; i < n; cin >> a[i++]);
	for (i = 0; i < n; cin >> b[i++]);
	sv();
}
