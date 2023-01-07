#include<bits/stdc++.h>
#define ll long long
#define N 200001
using namespace std;

map <ll, ll> M[N];
vector <pair<ll, ll>> Gr[N];
int C[N], G[N], Cy[N], D[N], dp[N][19];
ll W[N], sf[N];
ll n, q, o, i, j, w, cc, ccc;

void in()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (; o < n; o++)
	{
		cin >> i >> j >> w;
		if (i < j) swap(i, j);
		if (M[i].count(j))
		{
			ll t = M[i][j]; t = min(t, w);
			M[i][j] = t;
		}
		else
			M[i][j] = w;
	}
	for (i = 1; i <= n; i++)
		for (auto& a : M[i])
		{
			auto [j, w] = a;
			Gr[i].emplace_back(j, w);
			Gr[j].emplace_back(i, w);
			C[i]++, C[j]++;
		}
}
void f1()
{
	queue <ll> Q;
	ll V[N]{};
	for (i = 1; i <= n; i++)
		if (C[i] == 1)
			Q.push(i);
	while (Q.size())
	{
		i = Q.front(); Q.pop();
		V[i] = 1; Cy[i] = 1;
		for (auto& a : Gr[i])
			if (--C[a.first] == 1 && !V[a.first])
				Q.push(a.first);
	}
}
void f2(ll p, ll q, ll c, ll d)
{
	G[p] = q; D[p] = d;
	for (auto& a : Gr[p])
		if (Cy[a.first] && !G[a.first])
		{
			W[a.first] = c + a.second;
			dp[a.first][0] = p;
			f2(a.first, q, W[a.first], d + 1);
		}
}
void f3()
{
	for (j = 1; j < 19; j++)
		for (i = 1; i <= n; i++)
			dp[i][j] = dp[dp[i][j - 1]][j - 1];
}
ll f4(ll p, ll q)
{
	if (D[p] < D[q])
		swap(p, q);
	ll w = D[p] - D[q];
	for (o = 0; w; w >>= 1, o++)
		if (w & 1)
			p = dp[p][o];
	if (p ^ q)
	{
		for (o = 18; o >= 0; o--)
			if (dp[p][o] ^ dp[q][o])
				p = dp[p][o], q = dp[q][o];
		p = dp[p][0];
	}
	return p;
}
void f5(ll p, ll q, ll d)
{
	sf[p] = q, D[p] = d;
	for (auto& a : Gr[p])
	{
		if (a.first == ccc)
			sf[ccc] = q + a.second;
		if (!Cy[a.first] && !D[a.first])
			f5(a.first, q + a.second, d + 1);
	}
}
int main()
{
	in();
	f1();
	for (i = 1; i <= n; i++)
		if (!Cy[i])
		{
			cc = 1, f2(i, i, 0, 1);
			if (!ccc)
				ccc = i;
			D[i] = 0;
		}
	if (!cc)
		f2(1, 1, 0, 1);
	else
	{
		f5(ccc, 0, 1);
		i = sf[ccc]; sf[ccc] = 0; ccc = i;
	}
	f3();
	cin >> q;
	while (q--)
	{
		cin >> i >> j;
		if (G[i] == G[j])
			cout << W[i] + W[j] - 2 * W[f4(i, j)] << '\n';
		else
		{
			ll s = W[i] + W[j];
			i = G[i], j = G[j];
			if (D[i] < D[j]) swap(i, j);
			ll temp = sf[i] - sf[j];
			temp = min(temp, ccc - temp);
			cout << s + temp << '\n';
		}
	}
}
