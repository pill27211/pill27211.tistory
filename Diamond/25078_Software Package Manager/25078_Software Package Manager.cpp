#include<bits/stdc++.h>
#define r int n, int s, int e
#define N 100001
using namespace std;

vector <int> Gr[N], G[N];
int top[N], in[N], out[N];
int D[N], P[N], S[N];
int seg[1 << 18], lz[1 << 18];
int n, q, i, j;

void f0()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (cin >> n; i < n - 1;)
		cin >> j, Gr[j].push_back(++i);
}
void f1(int p)
{
	S[p] = 1;
	for (int& a : Gr[p])
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
	out[p] = q;
}
void f3(r)
{
	if (!!~lz[n])
		if (seg[n] = lz[n] * (e - s + 1); s ^ e)
			lz[n << 1] = lz[n], lz[n << 1 | 1] = lz[n];
	lz[n] = -1;
}
int f4(r, int p, int q, int k)
{
	f3(n, s, e);
	if (s > q || e < p) return seg[n];
	if (s >= p && e <= q)
	{
		lz[n] = k;
		f3(n, s, e);
		return seg[n];
	}
	return seg[n] = f4(n << 1, s, (s + e) >> 1, p, q, k) + f4(n << 1 | 1, ((s + e) >> 1) + 1, e, p, q, k);
}
int f5(r, int p, int q)
{
	f3(n, s, e);
	if (s > q || e < p) return 0;
	if (s >= p && e <= q) return seg[n];
	return f5(n << 1, s, (s + e) >> 1, p, q) + f5(n << 1 | 1, ((s + e) >> 1) + 1, e, p, q);
}
int f6(int p, int q, int k, int x = 0)
{
	while (top[p] ^ top[q])
	{
		if (D[top[p]] < D[top[q]]) swap(p, q);
		x += f5(1, 1, n, in[top[p]], in[p]);
		f4(1, 1, n, in[top[p]], in[p], k);
		p = P[top[p]];
	}
	if (D[p] > D[q]) swap(p, q);
	x += f5(1, 1, n, in[p], in[q]);
	return f4(1, 1, n, in[p], in[q], k), x;
}
int main()
{
	f0();
	f1(0); f2(0);
	cin >> q;
	for (string s; q--;)
	{
		cin >> s >> i;
		if (s == "install")
			cout << D[i] - f6(0, i, 1) + 1 << '\n';
		else
			cout << f5(1, 1, n, in[i], out[i]) << '\n', f4(1, 1, n, in[i], out[i], 0);
	}
}
