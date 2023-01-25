#include<bits/stdc++.h>
using namespace std;

struct E
{
	int p, q, w;
	bool operator<(E& e) { return w < e.w; }
};
vector <E> Eg;
int n, k, P[1001];

void in()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i(1); i <= n; i++)
		for (int j(1); j <= n; j++)
		{
			cin >> k;
			if (i < j) Eg.push_back({ i, j, k });
		}
	sort(Eg.begin(), Eg.end());
}
int f(int p) { return P[p] = P[p] == p ? p : f(P[p]); }
void sv()
{
	long long s{};
	iota(P, P + 1001, 0);
	for(auto& i : Eg)
	{
		int p(f(i.p)), q(f(i.q));
		if (p ^ q)
			s += i.w, p > q ? P[p] = q : P[q] = p;
	}
	cout << s;
}
int main()
{
	in();
	sv();
}
