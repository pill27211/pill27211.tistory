#include<bits/stdc++.h>
#define N 1000001
using namespace std;

int r[N], s[N];
int p[N], a[N];
int n, i, j, c;

void f1()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	iota(p + 1, p + N, 1);
	iota(r + 1, r + N, 1);
	for (i = 2; i * i < N; i++)
		if (p[i] == i)
			for (j = i + i; j < N; j += i)
				if (p[j] == j)
					p[j] = i;
}
int f2(int p)
{
	return r[p] = r[p] == p ? p : f2(r[p]);
}
void f3(int p, int q)
{
	p = f2(p), q = f2(q);
	if (p > q)
		r[p] = q, s[q] += s[p];
	else if (p < q)
		r[q] = p, s[p] += s[q];
}
void sv()
{
	cin >> n;
	for (i = 1; i <= n; i++)
		cin >> a[i], s[a[i]]++;
	for (i = 1; i <= n; i++)
	{
		int t = a[i];
		while (t / p[t] ^ 1)
			f3(p[a[i]], t / p[t]), f3(p[a[i]], p[t]), t /= p[t];
		f3(p[a[i]], a[i]);
	}
	cout << *max_element(s, s + N);
}
int main()
{
	f1();
	sv();
}