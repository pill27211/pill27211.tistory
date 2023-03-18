#include<bits/stdc++.h>
using namespace std;

unordered_map <string, priority_queue <int>> M;
long long q, o, n, i, r;
string s;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> q;
	while (q--)
	{
		cin >> o >> s >> n;
		if (o & 1)
			while (n--)
				cin >> i, M[s].push(i);
		else
			while (n-- && M[s].size())
				r += M[s].top(), M[s].pop();
	}
	cout << r;
}
