#include<bits/stdc++.h>
using namespace std;

unordered_map <string, int> M;
vector <pair<int, int>> Gr[501];
string s, e;
int t, n, c, w;

int f()
{
	priority_queue <pair<int, int>> Q;
	vector <int> D(501, 1e9);
	Q.push({0, M[s]}); D[M[s]] = 0;
	while(Q.size())
	{
		auto [x, y] = Q.top();
		x *= -1; Q.pop();
		if(D[y] >= x)
			for(auto& [a, b] : Gr[y])
				if(w = x + b; w < D[a])
					D[a] = w, Q.push({-w, a});
	}
	return D[M[e]];
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	for(cin >> t; t--; M.clear())
	{
		cin >> n >> s >> e;
		M[s] = ++c, M[e] = ++c;
		for(string x, y; n--;)
		{
			cin >> x >> y >> w;
			if(!M.count(x)) M[x] = ++c;
			if(!M.count(y)) M[y] = ++c;
			Gr[M[x]].emplace_back(M[y], w);
			Gr[M[y]].emplace_back(M[x], w);
		}
		cout << s << ' ' << e << ' ' << f() << '\n';
		for(n = 0; n < 501; Gr[n++].clear());
	}
}
