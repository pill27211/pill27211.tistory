#include<bits/stdc++.h>
using namespace std;

vector <string> V;
string s;
int n, k;
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
			for (int i{}; i < c * 2; i++)
				cout << '-';
			cout << x << '\n';
			y->trav(c + 1);
		}
	}
};
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	T* R(new T{});
	for (cin >> n; n--; R->push(0), V.clear())
		for (cin >> k; k--;)
			cin >> s, V.emplace_back(s);
	R->trav(0);
}
