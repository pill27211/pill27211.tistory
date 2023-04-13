#include<bits/stdc++.h>
using namespace std;

vector <string> V;
string s;
struct T
{
	map <string, T*> p;
	void push(int i)
	{
		if (i < V.size())
		{
			if (!p.count(V[i])) p[V[i]] = new T{};
			p[V[i]]->push(i + 1);
		}
	}
	void trav(int c)
	{
		for (auto& [x, y] : p)
		{
			for (int i{}; i < c; cout << ' ', i++);
			cout << x << '\n';
			y->trav(c + 1);
		}
	}
};
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	T* R(new T{});
	int n; cin >> n;
	for (string s; n--;)
	{
		int i{}, j{};
		for (cin >> s; i < s.size(); i++)
			if (s[i] == '\\')
				V.emplace_back(s.substr(j, i - j)), j = i + 1;
		V.emplace_back(s.substr(j, s.size() - j));
		R->push(0); V.clear();
	}
	R->trav(0);
}
