#include<bits/stdc++.h>
#define V vector <vector <S>>
using namespace std;

int dy[]{ 0, -1, -1, 0, 1, 1, 1, 0, -1 }, dx[]{ 0, 0, -1, -1, -1, 0, 1, 1, 1 };
struct S { int a, b, y, x, w; }I({ 0, 0, 1, 1 });
V M(5, vector <S>(5));

void in()
{
	for (int i = 1; i < 5; i++)
		for (int j = 1; j < 5; j++)
			cin >> M[i][j].a >> M[i][j].b, M[i][j].y = i, M[i][j].x = j;
	I.b = M[1][1].b, M[1][1].w = 1;
}
V fmove(V p, S q)
{
	for (int i = 1; i < 17; i++)
	{
		S t{};
		for (int j = 1; j < 5; j++)
			for (int l = 1; l < 5; l++)
				if (p[j][l].a == i)
					t = p[j][l];
		if (t.w) continue;
		int j = t.b;
		do
		{
			int y(t.y + dy[j]), x(t.x + dx[j]);		
			if (y && x && y < 5 && x < 5 && (y ^ q.y || x ^ q.x))
			{
				S a({ i, j, y, x, 0 }), b(p[y][x]);
				b.y = t.y, b.x = t.x;
				p[y][x] = a; p[t.y][t.x] = b;
				break;
			}
			j = max(1, (j + 1) % 9);
		} while (j ^ t.b);
	}
	return p;
}
int sv(V p, S q)
{
	V t(fmove(p, q));
	int i{}, j{};
	while (++i)
	{
		int y(q.y + dy[q.b] * i), x(q.x + dx[q.b] * i);
		if (y < 1 || x < 1 || y > 4 || x > 4) break;
		if (!t[y][x].w)
			t[y][x].w = 1, j = max(j, t[y][x].a + sv(t, { 0, t[y][x].b, y, x, 0 })), t[y][x].w = 0;
	}
	return j;
}
int main()
{
	in();
	cout << sv(M, I) + M[1][1].a;
}
