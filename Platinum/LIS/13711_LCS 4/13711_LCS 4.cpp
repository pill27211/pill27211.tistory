#include<bits/stdc++.h>
#define N 100001
using namespace std;

vector <int> V;
int a[N], b[N], t[N];
int n, i, j;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (; i < n; cin >> a[i++]);
	for (; j < n; j++)
		cin >> b[j], t[b[j]] = j;
	for (i = 0; i < n; i++)
		a[i] = t[a[i]];
	for (i = 0; i < n; i++)
	{
		j = lower_bound(V.begin(), V.end(), a[i]) - V.begin();
		j == (int)V.size() ? V.push_back(a[i]), 1 : V[j] = a[i];
	}
	cout << V.size();
}