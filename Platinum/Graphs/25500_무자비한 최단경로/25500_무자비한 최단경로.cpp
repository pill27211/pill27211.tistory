#include <bits/stdc++.h>
#define pb push_back
#define N 400001
using namespace std;

struct S
{
	int p, q;
	bool operator<(S& s) {return p ^ s.p ? p < s.p : q < s.q;}
};
vector <S> Vx, Vy, V[N];
int D[N];
int n, k, i, x, y, z;

void f1()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	fill(D, D + N, 2e9);
	cin >> n >> k;
	for (i = 1; i <= n; i++)
	{
		cin >> x >> y >> z;
		Vx.pb({ x, i });
		Vy.pb({ y, i });

		int p = z % k;
		V[i].pb({ n + 1 + p, z });
		V[n + 1 + (k - p) % k].pb({ i, z });
	}
}
void f2()
{
	sort(Vx.begin(), Vx.end());
	sort(Vy.begin(), Vy.end());
	for (i = 1; i < n; i++)
	{
		V[Vx[i].q].pb({ Vx[i - 1].q, abs(Vx[i].p - Vx[i - 1].p) });
		V[Vx[i - 1].q].pb({ Vx[i].q, abs(Vx[i].p - Vx[i - 1].p) });
		V[Vy[i].q].pb({ Vy[i - 1].q, abs(Vy[i].p - Vy[i - 1].p) });
		V[Vy[i - 1].q].pb({ Vy[i].q, abs(Vy[i].p - Vy[i - 1].p) });
	}
}
void f3()
{
	priority_queue <pair<int, int>> Q;
	Q.push({ 0, 1 }); D[1] = 0;
	while (Q.size())
	{
		auto [a, b] = Q.top();
		a *= -1, Q.pop();
		if (D[b] >= a)
			for (auto& i : V[b])
			{
				int d = a + i.q;
				if (d < D[i.p])
					D[i.p] = d, Q.push({ -d, i.p });
			}
	}
}
int main()
{
	f1();
	f2();
	f3();
	for (i = 1; i <= n; cout << D[i++] << '\n');
}
