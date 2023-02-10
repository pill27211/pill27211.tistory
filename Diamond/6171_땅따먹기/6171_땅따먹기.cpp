#include<bits/stdc++.h>
#define ll long long
#define N 50001
#define W first
#define H second
using namespace std;

struct S
{
	ll p, q;
	double d;
	bool operator<(int x) { return d < x; }
}ln[N];
vector <pair<int, int>> V;
pair<int, int> a[N];
ll n, u, i, dp[N];

inline double f(S& l, S& r) { return (r.q - l.q) / (l.p - r.p); }
void in()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (; i < n; i++)
		cin >> a[i].W >> a[i].H;
	sort(a, a + n, greater<>());
	V.emplace_back(a[0]);
	for (i = 1; i < n; i++)
		if (a[i].H > V.back().H)
			V.emplace_back(a[i]);
	n = V.size();
}
void sv()
{
	dp[0] = V[0].W * V[0].H;
	ln[u++] = { V[0].W, 0, 0 };
	for (i = 1; i < n; i++)
	{
		S t({ V[i].W, dp[i - 1], 0 });
		while (u)
		{
			t.d = f(t, ln[u - 1]);
			if (t.d > ln[u - 1].d) break;
			u--;
		}
		ln[u++] = t;
		ll j = lower_bound(ln, ln + u, V[i].H) - ln - 1;
		dp[i] = ln[j].p * V[i].H + ln[j].q;
	}
	cout << dp[n - 1];
}
int main()
{
	in();
	sv();
}
