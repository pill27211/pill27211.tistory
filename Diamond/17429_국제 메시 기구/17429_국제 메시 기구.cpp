#include<bits/stdc++.h>
#define r int n, int s, int e
#define ll unsigned int
#define N 500001
using namespace std;

vector <int> Gr[N], G[N];
ll seg[1 << 20], lz[1 << 20][2];
int top[N], in[N], out[N];
int S[N], P[N], D[N];
int n, q, o, i, j, k;

void f0()
{
	ios_base::sync_with_stdio(0);  cin.tie(0);
	cin >> n >> q;
	for (; i < n - 1; i++)
		cin >> j >> k, Gr[j].push_back(k), Gr[k].push_back(j);
}
void f1(int p)
{
	S[p] = 1;
	for (int i : Gr[p])
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
void f3(r)
{
	if (lz[n][0] == 1 && !lz[n][1])
		return;
	seg[n] *= lz[n][0];
	seg[n] += (e - s + 1) * lz[n][1];
	if (s ^ e)
	{
		lz[n << 1][0] *= lz[n][0], lz[n << 1][1] *= lz[n][0], lz[n << 1][1] += lz[n][1];
		lz[n << 1 | 1][0] *= lz[n][0], lz[n << 1 | 1][1] *= lz[n][0], lz[n << 1 | 1][1] += lz[n][1];
	}
	lz[n][0] = 1, lz[n][1] = 0;
}
ll f4(r, int p, int q, ll k, ll v)
{
	f3(n, s, e);
	if (s > q || e < p)
		return seg[n];
	if (s >= p && e <= q)
	{
		seg[n] *= k, seg[n] += (e - s + 1) * v;
		if (s ^ e)
		{
			lz[n << 1][0] *= k, lz[n << 1][1] *= k, lz[n << 1][1] += v;
			lz[n << 1 | 1][0] *= k, lz[n << 1 | 1][1] *= k, lz[n << 1 | 1][1] += v;
		}
		return seg[n];
	}
	int m = (s + e) >> 1;
	return seg[n] = f4(n << 1, s, m, p, q, k, v) + f4(n << 1 | 1, m + 1, e, p, q, k, v);
}
ll f5(r, int p, int q)
{
	f3(n, s, e);
	if (s > q || e < p)
		return 0;
	if (s >= p && e <= q)
		return seg[n];
	int m = (s + e) >> 1;
	return f5(n << 1, s, m, p, q) + f5(n << 1 | 1, m + 1, e, p, q);
}
void f6(int p, int q, int k)
{
	while (top[p] ^ top[q])
	{
		if (D[top[p]] < D[top[q]])
			swap(p, q);
		f4(1, 1, n, in[top[p]], in[p], 1, k);
		p = P[top[p]];
	}
	if (D[p] > D[q])
		swap(p, q);
	f4(1, 1, n, in[p], in[q], 1, k);
}
void f7(int p, int q, int k)
{
	while (top[p] ^ top[q])
	{
		if (D[top[p]] < D[top[q]])
			swap(p, q);
		f4(1, 1, n, in[top[p]], in[p], k, 0);
		p = P[top[p]];
	}
	if (D[p] > D[q])
		swap(p, q);
	f4(1, 1, n, in[p], in[q], k, 0);
}
ll f8(int p, int q)
{
	ll t = 0;
	while (top[p] ^ top[q])
	{
		if (D[top[p]] < D[top[q]])
			swap(p, q);
		t += f5(1, 1, n, in[top[p]], in[p]);
		p = P[top[p]];
	}
	if (D[p] > D[q])
		swap(p, q);
	t += f5(1, 1, n, in[p], in[q]);
	return t;
}
void f9()
{
	while (q--)
	{
		cin >> o >> i;
		if (o == 1)
			cin >> j, f4(1, 1, n, in[i], out[i], 1, j);
		else if (o == 2)
			cin >> j >> k, f6(i, j, k);
		else if (o == 3)
			cin >> j, f4(1, 1, n, in[i], out[i], j, 0);
		else if (o == 4)
			cin >> j >> k, f7(i, j, k);
		else if (o == 5)
			cout << f5(1, 1, n, in[i], out[i]) << '\n';
		else
			cin >> j, cout << f8(i, j) << '\n';
	}
}
int main()
{
	f0();
	f1(1); f2(1);
	f9();
}
