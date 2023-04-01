#include<bits/stdc++.h>
using namespace std;

string s;
char M[130];
int n;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (n = 65; n < 123; n++) M[n] = n;
	cin >> s >> n;
	for (char p, q, i; n--;)
		if (cin >> i; i & 1)
		{
			cin >> p >> q;
			for (i = 65; i < 123; i++)
				if (M[i] == p)
					M[i] = q;
		}
		else
		{
			for (char i : s) cout << M[i];
			cout << '\n';
		}
}
