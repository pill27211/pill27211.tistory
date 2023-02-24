#include<bits/stdc++.h>
using namespace std;

string p;
int i(1), j, l, pi[1000001];

int main()
{
	for (cin >> l >> p; i < l; i++)
	{
		while (j && p[i] ^ p[j]) j = pi[j - 1];
		if (p[i] == p[j]) pi[i] = ++j;
	}
	cout << l - pi[l - 1];
}
