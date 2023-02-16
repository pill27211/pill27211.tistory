#include <bits/stdc++.h>
#define ll long long
#define N 1000001
using namespace std;

struct S
{
	ll p, q;
	double d;
	bool operator<(int x) { return d < x; }
}ln[N];
ll n, u, a, b, c, i, A[N], dp[N];

ll g(ll x) { return a * A[x] * A[x] + b * A[x] + c; }
ll y(ll x) { return a * A[x] * A[x] - b * A[x] + dp[x]; };
double f(S& l, S& r) { return (r.q - l.q) / (l.p - r.p); }

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> a >> b >> c;
	for (i = 1; i <= n; i++)
		cin >> A[i], A[i] += A[i - 1];
	for (i = 1; i <= n; i++)
	{
		S t({ -2 * a * A[i - 1], y(i - 1), 0 });
		while (u)
		{
			t.d = f(t, ln[u - 1]);
			if (t.d > ln[u - 1].d) break;
			u--;
		}
		ln[u++] = t;
		ll j = lower_bound(ln, ln + u, A[i]) - ln - 1;
		dp[i] = ln[j].p * A[i] + ln[j].q + g(i);
	}
	cout << dp[n];
}
