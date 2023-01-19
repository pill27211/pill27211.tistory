#include<bits/stdc++.h>
using namespace std;

int dy[]{ -1, 1, 0, 0 }, dx[]{ 0, 0, -1, 1 };
priority_queue <tuple<int, int, int>> Q;
int n, i, j, a[51][51], v[51][51];


int main()
{
	cin >> n;
	for (; i < n; i++)
		for (j = 0; j < n; j++)
			scanf("%1d", &a[i][j]), a[i][j] ^= 1, v[i][j] = 2e9;
	Q.push({ 0, 0, 0 }); v[0][0] = 0;
	while (Q.size())
	{
		auto [d, y, x] = Q.top(); Q.pop();
		d *= -1;
		if (v[y][x] >= d)
			for (int k{}; k < 4; k++)
			{
				i = y + dy[k], j = x + dx[k];
				if (i >= 0 && j >= 0 && i < n && j < n)
				{
					int w(d + a[i][j]);
					if (w < v[i][j])
						v[i][j] = w, Q.push({ -w, i, j });
				}
			}
	}
	cout << v[n - 1][n - 1];
}
