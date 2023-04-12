#include<bits/stdc++.h>
#define N 1001
using namespace std;

vector <int> Gr[N];
int n, q, o, i, j, C[N];

int f(int p, int q, int c)
{
	int t(p == j ? c : 0);
	for (int x : Gr[p])
		if (!t && x ^ q)
			t = f(x, p, c + 1);
	return t ? (C[p] += t), c - 1 : 0;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (cin >> n; o++ < n - 1;)
		cin >> i >> j, Gr[i].push_back(j), Gr[j].push_back(i);
	for (cin >> q; q--;)
	{
		cin >> o >> i;
		if (o & 1) cin >> j, f(i, 0, 0);
		else cout << C[i] << '\n';
	}
}
