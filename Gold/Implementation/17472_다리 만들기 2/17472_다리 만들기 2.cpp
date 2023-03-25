#include<bits/stdc++.h>
#define F for (i = 1; i <= n; i++) for (j = 1; j <= m; j++)
using namespace std;

int dy[]{ -1, 1, 0, 0 }, dx[]{ 0, 0, -1, 1 };
struct S
{
	int p, q, w;
	bool operator<(S& s) { return w < s.w; }
};
vector <S> Gr;
int M[11][11], P[101];
int n, m, r, i, j, c(1);

int f(int p) { return P[p] = P[p] == p ? p : f(P[p]); }
int f(int y, int x) { return y && x && y <= n && x <= m; }
void f1()
{
	queue <pair<int, int>> Q;
	Q.push({ i, j }), M[i][j] = c;
	while (Q.size())
	{
		auto [a, b](Q.front()); Q.pop();
		for (int i{}; i < 4; i++)
			if (int y(a + dy[i]), x(b + dx[i]); f(y, x) && M[y][x] == 1)
				M[y][x] = c, Q.push({ y, x });
	}
}
void f2()
{
	for (int d{}; d < 4; d++)
	{
		int y(i + dy[d]), x(j + dx[d]), k{};
		for (; f(y, x) && !M[y][x]; k++)
			y += dy[d], x += dx[d];
		if (f(y, x) && M[y][x] ^ c && k > 1)
			Gr.push_back({ M[i][j], M[y][x], k });
	}
}
void in()
{
	cin >> n >> m;
	F
		cin >> M[i][j];
	F
		if (M[i][j] == 1)
			++c, f1();
	F
		if (M[i][j])
			f2();
}
void sv()
{
	iota(P, P + 101, 0), sort(Gr.begin(), Gr.end());
	for (auto [p, q, w] : Gr)
		if (p = f(p), q = f(q); p ^ q)
			r += w, p > q ? P[p] = q : P[q] = p;
	for (i = 2; i <= c; i++)
		if (f(i) ^ 2)
			cout << -1, exit(0);
	cout << r;
}
int main()
{
	in();
	sv();
}
