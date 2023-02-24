#include<bits/stdc++.h>
using namespace std;

int pi[1000003], an[1000003];
string p, q;
int i, j, l, r;

void f1()
{
	for (i = 1; i < (int)q.size(); i++)
	{
		while (j && q[i] ^ q[j]) j = pi[j - 1];
		if (q[i] == q[j]) pi[i] = ++j;
	}
}
void f2()
{
	l = q.size();
	for (i = j = 0; i < (int)p.size(); i++)
	{
		while (j && p[i] ^ q[j]) j = pi[j - 1];
		if (p[i] == q[j]) j == l - 1 ? an[r++] = i - l + 1, j = pi[j] : j++;
	}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	getline(cin, p), getline(cin, q);
	f1(); f2();
	cout << r << '\n';
	for (i = 0; i < r; cout << an[i++] + 1 << ' ');
}
