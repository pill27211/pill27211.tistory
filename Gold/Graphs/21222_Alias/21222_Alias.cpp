#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector <pair<int, int>> Gr[1001];
unordered_map <string, int> M;
ll D[1001][1001];
int n, m, i, c;

void f(int x)
{
	priority_queue <pair<ll, int>> Q;
	Q.push({ 0, x }); D[x][x] = 0;
	while (Q.size())
	{
		auto [a, b](Q.top());
		a *= -1; Q.pop();
		if (D[x][b] >= a)
			for (auto& [p, q] : Gr[b])
				if (ll w = a + q; D[x][p] > w)
					D[x][p] = w, Q.push({ -w, p });
	}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	fill(&D[0][0], &D[1000][1001], 1e18);
	cin >> n >> m;
	for (string x, y; m--;)
	{
		cin >> x >> y >> i;
		if (!M.count(x)) M[x] = ++c;
		if (!M.count(y)) M[y] = ++c;
		Gr[M[x]].emplace_back(M[y], i);
	}
	for (i = 1; i <= c; f(i++));
	cin >> c;
	for (string x, y; c--;)
		cin >> x >> y, (D[M[x]][M[y]] < 1e18 ? cout << D[M[x]][M[y]] << '\n' : cout << "Roger\n");
}
