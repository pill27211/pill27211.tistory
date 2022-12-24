#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector <pair<int, int>> Gr[50001];
int n, m, i, j, w;
ll r = 1e18;

void f()
{
	priority_queue <tuple<ll,int, int>> Q;
	Q.push({ 0, 0, i });
	while (!Q.empty())
	{
		auto[a, b, c] = Q.top(); Q.pop();
		a *= -1;

		if (c == j)
			r = min(r, a);
		for (auto& i : Gr[c])
			if (i.second > b)
				Q.push({ -(a + i.second), i.second, i.first });
	}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	while (m--)
		cin >> i >> j >> w, Gr[i].emplace_back(j, w), Gr[j].emplace_back(i, w);
	cin >> i >> j;
	f();
	r == 1e18 ? cout << "DIGESTA" : cout << r;
}
