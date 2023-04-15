#include<bits/stdc++.h>
using namespace std;

struct S
{
	int x, y, w;
	bool operator<(S& e) { return w > e.w; }
};
vector <S> Eg;
int t, n, m, P[222];

int f(int p) { return P[p] = P[p] == p ? p : f(P[p]); }
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	while (cin >> n >> m, n && m)
	{
		unordered_map <string, int> M;
		int i{}, c{};
		t++; Eg.clear();
		string s, e;
		for (iota(P, P + 222, 0); m--; Eg.push_back({ M[s], M[e], i }))
		{
			cin >> s >> e >> i;
			if (!M.count(s)) M[s] = ++c;
			if (!M.count(e)) M[e] = ++c;
		}
		cin >> s >> e;
		sort(Eg.begin(), Eg.end());
		for (auto& [x, y, w] : Eg)
		{
			int p(f(x)), q(f(y));
			if (p ^ q)
				i = w, p > q ? P[p] = q : P[q] = p;
			if (f(M[s]) == f(M[e]))
				break;
		}
		cout << "Scenario #" << t << '\n' << i << " tons\n\n";
	}
}
