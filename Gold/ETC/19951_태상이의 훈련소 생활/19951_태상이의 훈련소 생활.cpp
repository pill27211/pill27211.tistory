#include<bits/stdc++.h>
using namespace std;

int n, q, i, a[100005], p[100005];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> q;
	for (i = 1; i <= n; cin >> a[i++]);
	while (q--)
	{
		int x, y, h; cin >> x >> y >> h;
		p[x] += h; p[y + 1] -= h;
	}
	for (i = 1; i <= n; i++) p[i] += p[i - 1];
	for (i = 1; i <= n; i++) cout << a[i] + p[i] << ' ';
}
