#include<bits/stdc++.h>
using namespace std;

int n, k, i, t, p, q = 1, a[500050];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	while (i < n)
		cin >> a[i++];

	vector <int> M(n), C(n); M[0] = a[0];
	for (C[0] = i = 1, t = 2; i < n; t++, i++)
	{
		if (M[q - 1] >= a[i])
			C[q]++, M[q++] = a[i];
		else
		{
			int x = n - (lower_bound(M.rbegin(), M.rend() - p, a[i]) - M.rbegin());
			C[x]++, M[x] = a[i];
		}
		if (t - k == C[p])
			t -= C[p++];
	}
	cout << q;
}
