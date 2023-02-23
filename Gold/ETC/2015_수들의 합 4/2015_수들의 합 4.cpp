#include<bits/stdc++.h>
#define ll long long
using namespace std;

map <ll, ll> M{{0, 1}};
ll n, m, i, r, a[200001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for(i = 1; i <= n; i++)
	{
		cin >> a[i], a[i] += a[i - 1];
		r+= M[a[i] - m], M[a[i]]++;
	}
	cout << r;
}
