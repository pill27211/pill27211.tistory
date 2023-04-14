#include<bits/stdc++.h>
using namespace std;

unordered_map <string, string> S;
string p, q, s;
int n, m;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i{}; n--; i = 0)
		for (cin >> s; i < s.size(); i++)
		{
			string t(s.substr(0, i + 1));
			S.count(t) && t.size() > m ? m = t.size(), p = S[t], q = s : S[t] = s;
		}
	cout << p + '\n' + q;
}
