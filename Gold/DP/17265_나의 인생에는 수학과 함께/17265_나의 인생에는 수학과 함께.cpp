#include<bits/stdc++.h>
using namespace std;

int n, i, j;
char a[9][9];

int f0(int p, int q, int c)
{
	return c < 44 ? (c & 1 ? p + q : p * q) : (c % 5 ? p / q : p - q);
}
int f1(string s)
{
	int t = s[0] - 48;
	for (int i = 2; i < (int)s.size(); i += 2)
		t = f0(t, s[i] - 48, s[i - 1]);
	return t;
}
int f2(int p, int q, string s)
{
	if (p == n && q == n)
		return f1(s + a[p][q]);
	int t = -2e9;
	if (p + 1 <= n)
		t = max(t, f2(p + 1, q, s + a[p + 1][q]));
	if (q + 1 <= n)
		t = max(t, f2(p, q + 1, s + a[p][q + 1]));
	return t;
}
int f3(int p, int q, string s)
{
	if (p == n && q == n)
		return f1(s + a[p][q]);
	int t = 2e9;
	if (p + 1 <= n)
		t = min(t, f3(p + 1, q, s + a[p + 1][q]));
	if (q + 1 <= n)
		t = min(t, f3(p, q + 1, s + a[p][q + 1]));
	return t;
}
int main()
{
	cin >> n;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			cin >> a[i][j];
	string s; s += a[1][1];
	cout << f2(1, 1, s) << ' ' << f3(1, 1, s);
}
