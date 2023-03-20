#include<bits/stdc++.h>
#define D double
using namespace std;

struct E
{
	D p, q, w;
	bool operator<(E& e) { return w < e.w; }
}a[1001];
vector <E> Eg;
int v, P[1001];

int f(int p) { return P[p] = P[p] == p ? p : f(P[p]); }
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	while (cin >> v, v)
	{
		iota(P, P + 1001, 0); Eg.clear();
		for (int i(1); i <= v; i++)
		{
			cin >> a[i].p >> a[i].q;
			for (int j(1); j < i; j++)
				Eg.push_back({ (D)i, (D)j, sqrt(pow(a[i].p - a[j].p, 2) + pow(a[i].q - a[j].q, 2)) });
		}
		sort(Eg.begin(), Eg.end());
		D r{};
		for (auto& i : Eg)
		{
			int p(f(i.p)), q(f(i.q));
			if (p ^ q)
				r += i.w, p > q ? P[p] = q : P[q] = p;
		}
		cout << fixed << setprecision(2) << r << '\n';
	}
}
