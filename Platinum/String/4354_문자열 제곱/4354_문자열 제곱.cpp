#include<bits/stdc++.h>
using namespace std;

string p;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	while (cin >> p, p[0] ^ '.')
	{
		int i(1), j{}, l(p.size()), pi[1000001]{};
		for (; i < l; i++)
		{
			while (j && p[i] ^ p[j]) j = pi[j - 1];
			if (p[i] == p[j]) pi[i] = ++j;
		}
		i = l - pi[l - 1];
		cout << (l % i ? 1 : l / i) << '\n';
	}
}
