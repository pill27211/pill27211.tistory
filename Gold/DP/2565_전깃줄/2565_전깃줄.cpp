#include<bits/stdc++.h>
using namespace std;

int a[501], b[501], dp[501];
vector <int> V(1);
int n, r, i, j;

int main()
{
	cin >> n;
	for (; i < n; i++)
		cin >> j >> r, a[r] = j, b[r] = 1;
	for (i = 0; i < 501; i++)
		if (b[i])
			V.push_back(a[i]);
	for (r = 0, i = 1; i < (int)V.size(); i++)
		for (j = i - 1; j; j--)
			if (V[i] > V[j])
				dp[i] = max(dp[i], dp[j] + 1), r = max(r, dp[i]);
	cout << n - r - 1;
}