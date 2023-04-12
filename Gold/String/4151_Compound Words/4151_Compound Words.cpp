#include<bits/stdc++.h>
using namespace std;

set <string> S, R;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (string s; cin >> s; S.insert(s));
	for (auto& s : S)
		for (int i{}; i < s.size() - 1; i++)
			if (S.count(s.substr(0, i + 1)) && S.count(s.substr(i + 1, s.size() - i - 1)))
				R.insert(s), i = 1e9;
	for (auto& s : R) cout << s << '\n';
}
