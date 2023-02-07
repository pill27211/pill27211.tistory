#include<bits/stdc++.h>
#define N 100001
using namespace std;

vector <int> Gr[N];
bool V[N];
int n, s, d, r, D[N];

int f1(int p, int q)
{
	D[p] = 0;
	for (int i : Gr[p])
		if (D[i] == -1)
			D[p] = max(D[p], f1(i, q + 1));
	return ++D[p];
}
void f2(int p)
{
	V[p] = 1;
	for (int i : Gr[p])
		if (!V[i] && D[i] > d)
			r++, f2(i), r++;
}
int main()
{
	memset(D, -1, sizeof D);
	cin >> n >> s >> d;
	for (int i{}, a, b; i < n - 1; i++)
		cin >> a >> b, Gr[a].push_back(b), Gr[b].push_back(a);
	f1(s, 1); f2(s);
	cout << r;
}
