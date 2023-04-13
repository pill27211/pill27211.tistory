#include<bits/stdc++.h>
using namespace std;

int dy[]{ -1, 1, 0, 0, -1, -1, 1, 1 }, dx[]{ 0, 0, -1, 1, -1, 1, -1, 1 };
int sc[]{ 0, 0, 0, 1, 1, 2, 3, 5, 11 };
unordered_set <string> S, T;
string ms, t;
char M[4][4], V[4][4];
int n, i, j, r, c;

void f(string s, int p, int q)
{
	if (!T.count(s) && S.count(s))
	{
		r += sc[s.size()]; c++;
		if (ms.size() <= s.size())
			ms = ms.size() < s.size() ? s : (ms < s ? ms : s);
		T.insert(s);
	}
	if (s.size() < 8)
		for (int i{}; i < 8; i++)
			if (int y(p + dy[i]), x(q + dx[i]); y >= 0 && x >= 0 && y < 4 && x < 4 && !V[y][x])
				V[y][x] = 1, f(s + M[y][x], y, x), V[y][x] = 0;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (string s; n--; cin >> s, S.insert(s));
	for (cin >> n; n--; r = c = 0)
	{
		for (i = 0; i < 4; i++)
			for (j = 0; j < 4; cin >> M[i][j++]);
		for (i = 0; i < 4; i++)
			for (j = 0; j < 4; j++)
				V[i][j] = 1, f(t + M[i][j], i, j), V[i][j] = 0;
		cout << r << ' ' + ms + ' ' << c << '\n';
		ms.clear(), T.clear();
	}
}
