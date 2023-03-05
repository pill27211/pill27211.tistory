#include<bits/stdc++.h>
using namespace std;

struct E
{
	int p, q, w;
	bool operator<(E& e) { return w < e.w; }
};
int dy[]{ 0, -1 }, dx[]{ -1, 0 };
int n, M[1001][1001], P[1000001];
vector <E> Eg;

int f(int p) { return P[p] = P[p] == p ? p : f(P[p]); }
int main()
{
	iota(P, P + 1000001, 0);
	cin >> n;
	for (int i(1); i <= n; i++)
		for (int j(1); j <= n; j++)
		{
			scanf("%d", &M[i][j]);
			for (int k{}; k < 2; k++)
			{
				int y(i + dy[k]), x(j + dx[k]);
				if (y && x)
					Eg.push_back({ n * (i - 1) + j, n * (y - 1) + x, abs(M[i][j] - M[y][x]) });
			}
		}
	sort(Eg.begin(), Eg.end());
	for (auto& i : Eg)
	{
		int p(f(i.p)), q(f(i.q));
		if (p ^ q)
			p > q ? P[p] = q : P[q] = p;
		if (f(n * n) == 1)
			cout << i.w, exit(0);
	}
	cout << 0;
}
