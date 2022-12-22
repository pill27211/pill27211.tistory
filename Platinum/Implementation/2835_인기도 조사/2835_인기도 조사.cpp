#include<iostream>
#include<string>
#define r int n, int s, int e
#define ll long long
#define N 86400
using namespace std;

string s1, s2, s3;
ll seg[1 << 18], lz[1 << 18];
int n, o, i, j;

int f1(string& _s)
{
	int h = stoi(_s.substr(0, 2));
	int m = stoi(_s.substr(3, 2));
	int s = stoi(_s.substr(6, 2));
	return (h * 60 + m) * 60 + s + 1;
}
void f2(r)
{
	if (lz[n])
	{
		seg[n] += lz[n] * (e - s + 1);
		if (s ^ e)
			lz[n << 1] += lz[n], lz[n << 1 | 1] += lz[n];
		lz[n] = 0;
	}
}
void f3(r, int p, int q)
{
	f2(n, s, e);
	if (s > q || e < p)
		return;
	if (s >= p && e <= q)
	{
		seg[n] += (e - s + 1);
		if (s ^ e)
			lz[n << 1] += 1, lz[n << 1 | 1] += 1;
		return;
	}
	int m = (s + e) >> 1;
	f3(n << 1, s, m, p, q);
	f3(n << 1 | 1, m + 1, e, p, q);
	seg[n] = seg[n << 1] + seg[n << 1 | 1];
}
ll f4(r, int p, int q)
{
	f2(n, s, e);
	if (s > q || e < p)
		return 0;
	if (s >= p && e <= q)
		return seg[n];
	int m = (s + e) >> 1;
	return f4(n << 1, s, m, p, q) + f4(n << 1 | 1, m + 1, e, p, q);
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> s1 >> s2 >> s3;
		int p = f1(s1), q = f1(s3);
		p <= q ? f3(1, 1, N, p, q) : (f3(1, 1, N, p, N), f3(1, 1, N, 1, q));
	}
	cout << fixed;
	cout.precision(10);
	cin >> o;
	while (o--)
	{
		cin >> s1 >> s2 >> s3;
		int p = f1(s1), q = f1(s3);
		cout << (p <= q ? f4(1, 1, N, p, q) / (double)(q - p + 1) : (seg[1] - f4(1, 1, N, q + 1, p - 1)) / (double)(N - p + 1 + q)) << '\n';
	}
}