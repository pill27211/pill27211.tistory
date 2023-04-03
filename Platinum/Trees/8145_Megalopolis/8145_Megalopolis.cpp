#include<bits/stdc++.h>
#define r int n, int s, int e
#define N 250001
using namespace std;

vector <int> Gr[N], G[N];
int top[N], in[N], C[N];
int D[N], P[N], S[N];
int seg[1 << 19];
int n, q, i, j;

void f0()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (cin >> n; q++ < n - 1;)
		cin >> i >> j, Gr[i].push_back(j), Gr[j].push_back(i);
}
void f1(int p)
{
	S[p] = 1;
	for (int& a : Gr[p])
		if (!S[a])
		{
			D[a] = D[p] + 1;
			P[a] = p;
			f1(a);
			S[p] += S[a];
			G[p].push_back(a);
			if (S[a] > S[G[p][0]]) swap(G[p][0], G[p].back());
		}
}
void f2(int p)
{
	in[p] = ++q;
	for (int& a : G[p])
		top[a] = a == G[p][0] ? top[p] : a, f2(a);
}
int f3(r, int p, int q)
{
	if (s > p || e < p) return seg[n];
	if (s == e) return seg[n] = q;
	return seg[n] = f3(n << 1, s, (s + e) >> 1, p, q) + f3(n << 1 | 1, ((s + e) >> 1) + 1, e, p, q);
}
int f4(r, int p, int q)
{
	if (s > q || e < p) return 0;
	if (s >= p && e <= q) return seg[n];
	return f4(n << 1, s, (s + e) >> 1, p, q) + f4(n << 1 | 1, ((s + e) >> 1) + 1, e, p, q);
}
int f5(int p, int q, int g = 0)
{
	while (top[p] ^ top[q])
	{
		if (D[top[p]] < D[top[q]]) swap(p, q);
		g += f4(1, 1, n, in[top[p]], in[p]);
		p = P[top[p]];
	}
	if (D[p] > D[q]) swap(p, q);
	return g + f4(1, 1, n, in[p] + 1, in[q]);
}
void sv()
{
	for (i = 1; i <= n; i++) f3(1, 1, n, in[i], 1);
	cin >> q; q += n - 1;
	for (char c; q--;)
	{
		cin >> c >> i;
		if (c == 'A') cin >> j, f3(1, 1, n, in[P[i] == j ? i : j], 0);
		else cout << f5(1, i) << '\n';
	}
}
int main()
{
	f0(); q = 0;
	f1(1); f2(1);
	sv();
}
