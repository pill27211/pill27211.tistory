#include <bits/stdc++.h>
using namespace std;

deque<pair<int, int>> dq;
int n, l, i, a[5000000];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> l;
	for (; i < n; cin >> a[i++]);
	for (i = 0; i < n; i++)
	{
		if (dq.size() && dq.front().second <= i - l)
			dq.pop_front();
		while (dq.size() && dq.back().first > a[i])
			dq.pop_back();

		dq.push_back({ a[i], i });
		cout << dq.front().first << " ";
	}
}
