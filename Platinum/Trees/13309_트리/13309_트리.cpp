#include<bits/stdc++.h>
#define r int n, int s, int e, int p
#define N 200001
using namespace std;

vector <int> Gr[N], G[N];
int top[N], in[N], out[N];
int S[N], P[N], D[N];
int seg[1 << 19];
int n, q, o, i, j;

void f0()
{
	ios_base::sync_with_stdio(0);  cin.tie(0);
	cin >> n >> q;
	for (i = 2; i <= n; i++)
		cin >> j, Gr[j].push_back(i), Gr[i].push_back(j);
}
void f1(int p)
{
	S[p] = 1;
	for (auto i : Gr[p])
		if (!S[i])
		{
			D[i] = D[p] + 1;
			P[i] = p;
			f1(i);
			S[p] += S[i];
			G[p].push_back(i);
			if (S[i] > S[G[p][0]]) swap(G[p][0], G[p].back());
		}
}
void f2(int p)
{
	in[p] = ++o;
	for (int i : G[p])
		top[i] = i == G[p][0] ? top[p] : i, f2(i);
	out[p] = o;
}
int f3(r)
{
	if (s > p || e < p)
		return seg[n];
	if (s == e)
		return ++seg[n];
	int m = (s + e) >> 1;
	return seg[n] = f3(n << 1, s, m, p) + f3(n << 1 | 1, m + 1, e, p);
}
int f4(r, int q)
{
	if (s > q || e < p)
		return 0;
	if (s >= p && e <= q)
		return seg[n];
	int m = (s + e) >> 1;
	return f4(n << 1, s, m, p, q) + f4(n << 1 | 1, m + 1, e, p, q);
}
int f5(int p, int q)
{
	while (top[p] ^ top[q])
	{
		if (D[top[p]] < D[top[q]])
			swap(p, q);
		if (f4(1, 1, n, in[top[p]], in[p]))
			return 1;
		p = P[top[p]];
	}
	if (D[p] > D[q])
		swap(p, q);
	return f4(1, 1, n, in[p] + 1, in[q]);
}
void f6()
{
	while (q--)
	{
		cin >> i >> j >> o;
		int k = f5(i, j);
		cout << (k ? "NO" : "YES") << '\n';
		if (o)
			f3(1, 1, n, in[k ? j : i]);
	}
}
int main()
{
	f0();
	f1(1); f2(1);
	f6();
}
