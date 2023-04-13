#include<bits/stdc++.h>
using namespace std;

unordered_map <string, int> M;
unordered_set <string> S;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for (string s, t; n--; cout << '\n')
	{
		bool f{};
		cin >> s; M[s]++;
		for (int i{}; i < s.size(); i++)
		{
			t = s.substr(0, i + 1);
			if (!f && !S.count(t))
				cout << t, f = 1;
			S.insert(t);
		}
		if (!f)
			M[s] == 1 ? S.insert(s), cout << s : cout << s + to_string(M[s]);
	}
}
