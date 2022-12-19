#include<bits/stdc++.h>
#define N 501
using namespace std;

vector <pair<int, int>> Gr[N];
vector <int> P[N];
int D[N], V[N][N];
int n, m, p, q, i, j, w;

void f1()
{
	priority_queue <pair<int, int>> Q;
	fill(D, D + N, 2e9);
	Q.push({ 0, p });
	D[p] = 0;

	while (Q.size())
	{
		auto[a, b] = Q.top(); Q.pop();
		a *= -1;
		if (D[b] >= a)
			for (auto& i : Gr[b])
			{
				w = a + i.second;
				if (!V[b][i.first] && D[i.first] > w)
				{
					P[i.first].clear();
					P[i.first].push_back(b);
					D[i.first] = w, Q.push({ -w, i.first });
				}
				else if (D[i.first] == w)
					P[i.first].push_back(b);
			}
	}
}
void f2()
{
	queue <int> Q;
	bool VV[N]{};
	VV[q] = 1;
	Q.push(q);
	while (Q.size())
	{
		int t = Q.front(); Q.pop();
		for (auto& a : P[t])
		{
			V[a][t] = 1;
			if (!VV[a])
				VV[a] = 1, Q.push(a);
		}
	}
}
void f3()
{
	cout << (D[q] == 2e9 ? -1 : D[q]) << '\n';
	for (i = 0; i < N; i++)
		Gr[i].clear(), P[i].clear(), fill(&V[i][0], &V[i][0] + N, 0);
}
int main()
{
	while (1)
	{
		cin >> n >> m;
		if (!(n + m))
			break;
		cin >> p >> q;
		while (m--)
			cin >> i >> j >> w, Gr[i].emplace_back(j, w);
		f1(); f2(); f1(), f3();
	}
}
