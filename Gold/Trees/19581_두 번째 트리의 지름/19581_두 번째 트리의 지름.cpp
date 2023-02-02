#include<bits/stdc++.h>
using namespace std;

vector <pair<int, int>> Gr[100001];
int n, i, j, w, v;

int f(int p, int q)
{
	queue <pair<int, int>> Q;
	bool V[100001]{};
	Q.push({ p, 0 });
	w = 0, V[p] = 1;
	while (Q.size())
	{
		auto [a, b] = Q.front(); Q.pop();
		for (auto& i : Gr[a])
			if (!V[i.first] && i.first ^ q)
			{
				V[i.first] = 1;
				if (w < b + i.second)
					w = b + i.second, v = i.first;
				Q.push({ i.first, b + i.second });
			}
	}
	return w;
}
int main()
{
	cin >> n; n--;
	while (n--)
		scanf("%d %d %d", &i, &j, &w), Gr[i].emplace_back(j, w), Gr[j].emplace_back(i, w);
	f(1, 0);
	i = v; f(v, 0); j = v;
	cout << max(f(i, j), f(j, i));
}
