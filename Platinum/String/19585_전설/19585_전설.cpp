#include<bits/stdc++.h>
using namespace std;

unordered_set <string> S;
string s;
struct T
{
	map <char, T*> p;
	bool x{};
	void push(int i)
	{
		if (i == s.size()) x = 1;
		else
		{
			char t(s[i]);
			if (!p.count(t)) p[t] = new T();
			p[t]->push(i + 1);
		}
	}
	int f(int i)
	{
		if (!p.count(s[i]) || i == s.size()) return 0;
		if (p[s[i]]->x && S.count(s.substr(i + 1))) return 1;
		return p[s[i]]->f(i + 1);
	}
};
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	T R{};
	while (n--) cin >> s, R.push(0);
	while (m--) cin >> s, S.insert(s);
	for (cin >> n; n--;) cin >> s, cout << (R.f(0) ? "Yes" : "No") << '\n';
}
