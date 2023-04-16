#include<bits/stdc++.h>
using namespace std;

struct T
{
	map <char, T*> p;
	int x{};
	void push(string& s, int i)
	{
		if (i == s.size()) x = 1;
		else
		{
			if (!p.count(s[i])) p[s[i]] = new T();
			p[s[i]]->push(s, i + 1);
		}
	}
	int f(string& s, int i, int c)
	{
		return i == s.size() ? c : p[s[i]]->f(s, i + 1, c + (p[s[i]]->x || p[s[i]]->p.size() ^ 1));
	}
	~T() { for (auto& i : p) delete i.second; }
};
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int n; cin >> n;)
	{
		vector <string> V(n);
		T* R(new T());
		double avg{};

		for (auto& i : V) cin >> i, R->push(i, 0);
		for (auto& i : V) avg += R->f(i, 0, 0);

		cout << fixed << setprecision(2) << avg / V.size() << '\n';
		delete R;
	}
}
