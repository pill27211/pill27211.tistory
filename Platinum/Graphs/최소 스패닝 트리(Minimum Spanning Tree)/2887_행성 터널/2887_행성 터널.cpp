#include<bits/stdc++.h>
#define P pair<int, int>
#define F first
#define S second
using namespace std;

vector <pair<int, P>> V;
vector <P> Vx, Vy, Vz;
int R[100000];
int N, p, q, i, j, r;

void in()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	iota(R, R + 100000, 0);
	cin >> N;
	for (i = 0; i < N; i++)
	{
		cin >> p >> q >> j;
		Vx.push_back({ p, i });
		Vy.push_back({ q, i });
		Vz.push_back({ j, i });
	}
}
int f1(int p)
{
	return R[p] = R[p] == p ? p : f1(R[p]);
}
void f2()
{
	sort(Vx.begin(), Vx.end());
	sort(Vy.begin(), Vy.end());
	sort(Vz.begin(), Vz.end());

	for (i = 1; i < N; i++)
	{
		V.push_back({ Vx[i].F - Vx[i - 1].F,{ Vx[i].S, Vx[i - 1].S } });
		V.push_back({ Vy[i].F - Vy[i - 1].F,{ Vy[i].S, Vy[i - 1].S } });
		V.push_back({ Vz[i].F - Vz[i - 1].F,{ Vz[i].S, Vz[i - 1].S } });
	}
	sort(V.begin(), V.end());
	for (auto& i : V)
	{
		p = f1(i.S.F);
		q = f1(i.S.S);
		if (p ^ q)
			p > q ? R[p] = q : R[q] = p, r += i.first;
	}
	cout << r;
}
int main()
{
	in();
	f2();
}