#include<bits/stdc++.h>
using namespace std;

struct S { int x, y, w; } V[20];
int n, c, r(1e9), dp[20][1 << 15];
map <string, int> M;

int f(int p, int q)
{
	if (q == (1 << c) - 1) return abs(V[p].x) + abs(V[p].y);
	int& t(dp[p][q]), i{};
	if (!~t)
		for (t = 1e9; i < n; i++)
			if (!(q & (1 << V[i].w)))
				t = min(t, f(i, q | (1 << V[i].w)) + abs(V[i].x - V[p].x) + abs(V[i].y - V[p].y));
	return t;
}
int main()
{
	memset(dp, -1, sizeof dp);
	cin >> n;
	for (int p, q, i{}; i < n; i++)
	{
		string s; cin >> p >> q >> s;
		if (!M.count(s)) M[s] = c++;
		V[i] = { p, q, M[s] };
	}
	for (int i{}; i < n; i++)
		r = min(r, f(i, 1 << V[i].w) + abs(V[i].x) + abs(V[i].y));
	cout << r;
}
