#include<bits/stdc++.h>
using namespace std;

vector <pair<int, int>> Gr[101];
int n, m, k, c[101];
bool V[101][1 << 15];

void in()
{
	cin >> n >> m >> k;
	for (int i, j{}; k--;)
		cin >> i, c[i] = ++j;
	for (int i, j, w; m--;)
		scanf("%d %d %d", &i, &j, &w), Gr[i].emplace_back(j, w), Gr[j].emplace_back(i, w);
}
void sv()
{
	queue <pair<int, int>> Q;
	Q.push({ 1, 0 }), V[1][0] = 1;
	if (c[1]) Q.push({ 1, 1 << c[1] }), V[1][1 << c[1]] = 1;
	while (Q.size())
	{
		auto [a, b](Q.front()); Q.pop();
		int t(__builtin_popcount(b));
		if (a == 1) k = max(k, t);
		for (auto& [p, q] : Gr[a])
			if (t <= q && !V[p][b])
			{
				V[p][b] = 1, Q.push({ p, b });
				if (c[p]) Q.push({ p, b | (1 << c[p]) });
			}
	}
	cout << k;
}
int main()
{
	in();
	sv();
}
