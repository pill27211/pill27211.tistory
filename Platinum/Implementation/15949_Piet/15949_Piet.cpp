#include<bits/stdc++.h>
#define P pair<int, int>
#define F first
#define S second
using namespace std;

int dy[] = { 0, -1, 0, 1, 0 }, dx[] = { 0, 0, 1, 0, -1 };
vector <P> V1, V2;
char M[105][105];
int dp, cc, p, q, f, c;
int n, m, i, j;
string an;

void in()
{
	cin >> n >> m;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			cin >> M[i][j];
	p = q = cc = 1;  dp = 2;
}
void find1()
{
	V1.clear(); V2.clear();
	queue <P> Q;
	bool V[105][105]{};
	V1.emplace_back(p, q);
	Q.push({ p, q });
	V[p][q] = 1;

	while (Q.size())
	{
		auto[a, b] = Q.front(); Q.pop();

		for (i = 1; i <= 4; i++)
		{
			int y = a + dy[i], x = b + dx[i];
			if (y && x && y <= n && x <= m)
				if (M[y][x] == M[a][b] && !V[y][x])
					V[y][x] = 1, V1.emplace_back(y, x), Q.push({ y, x });
		}
	}
}
void candidate()
{
	i = max_element(V1.begin(), V1.end(), [](P& p, P& q) { return dp < 3 ? (dp & 1 ? p.F > q.F : p.S < q.S) : (dp & 1 ? p.F < q.F : p.S > q.S); }) - V1.begin();
	int p, q;
	dp & 1 ? (p = V1[i].F, q = 0) : (p = 0, q = V1[i].S);
	for (auto& a : V1)
		if (a.F == p || a.S == q)
			V2.emplace_back(a);
}
void fnext()
{
	int t = dp + (cc & 1 ? -1 : 1);
	if (!t || t == 5)
		t = !t ? 4 : 1;
	sort(V2.begin(), V2.end(), [&t](P& p, P& q) { return t < 3 ? (t & 1 ? p.F < q.F : p.S > q.S) : (t & 1 ? p.F > q.F : p.S < q.S); });
	p = V2[0].F, q = V2[0].S;
}
int find2()
{
	int y = p + dy[dp], x = q + dx[dp];
	if (y && x && y <= n && x <= m && M[y][x] ^ 'X')
	{
		p = y, q = x;
		return 1;
	}
	return 0;
}
void change()
{
	c = 0;
	while (1)
	{
		c++;
		if (c > 9)
			cout << an, exit(0);
		cc = cc == 1 ? 2 : 1;
		fnext();
		if (find2())
			return;
		dp++;
		if (dp == 5)
			dp = 1;
		find1();
		candidate();
		fnext();
		if (find2())
			return;
	}
}
void check()
{
	if (find2())
		return;
	change();
}
int main()
{
	in();
	while (1)
	{
		an += M[p][q];
		find1();
		candidate();
		fnext();
		check();
	}
}