#include<bits/stdc++.h>
#define N 200001
using namespace std;

vector <int> Gr[N];
int n, i, j, c[N], d[N];

void f(int p, int q)
{
	d[p] = d[q] + 1;
	for (int i : Gr[p])
		if (i ^ q)
			f(i, p);
	d[p] = c[p] ? d[p] : 0;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int o{}; o++ < n - 1;)
		cin >> i >> j, Gr[i].push_back(j), Gr[j].push_back(i);
	for (i = 1; i <= n; cin >> c[i++]);
	f(1, 0), sort(d, d + n + 1);
	for (i = 1; i < n; i++)
		if (d[i] && d[i] >= d[i + 1])
			d[i + 1] = ++d[i];
	cout << d[n];
}
