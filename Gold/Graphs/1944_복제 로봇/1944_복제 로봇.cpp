#include<bits/stdc++.h>
using namespace std;

int dy[]{ -1, 1, 0, 0 }, dx[]{ 0, 0, -1, 1 };
struct E
{
	int p, q, w;
	bool operator<(E& e) { return w < e.w; }
};
vector <E> Eg;
int n, m, i, j, c, r, P[255], M[51][51];

int f(int p) { return P[p] = P[p] == p ? p : f(P[p]); }
void g()
{
	queue <pair<int, int>> Q;
	int V[51][51]{};
	Q.push({ i, j }), V[i][j] = 1;
	while (Q.size())
	{
		auto [a, b](Q.front()); Q.pop();
		for (int k{}; k < 4; k++)
		{
			int y(a + dy[k]), x(b + dx[k]);
			if (y && x && y <= n && x <= n && M[y][x] ^ 1 && !V[y][x])
			{
				V[y][x] = V[a][b] + 1;
				Q.push({ y, x });
				if (M[y][x] > 1) Eg.push_back({ M[i][j], M[y][x], V[y][x] - 1 });
			}
		}
	}
}
void in()
{
	iota(P, P + 255, 0); cin >> n >> m;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
		{
			char t; cin >> t;
			M[i][j] = t > 65 ? 2 + c++ : t - 48;
		}
	for (c = 0, i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			if (M[i][j] > 1)
				g();
}
void sv()
{
	sort(Eg.begin(), Eg.end());
	for (auto& [p, q, w] : Eg)
		if (i = f(p), j = f(q); i ^ j)
			c++, r += w, (i > j ? P[i] = j : P[j] = i);
	cout << (c == m ? r : -1);
}
int main()
{
	in();
	sv();	
}
