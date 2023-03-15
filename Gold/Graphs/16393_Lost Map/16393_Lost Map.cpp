#include<bits/stdc++.h>
using namespace std;

struct S
{
	int p, q, w;
	bool operator<(S& t) { return w < t.w; }
};
vector <S> Eg;
int n, P[2501];

int f(int p) { return P[p] = P[p] == p ? p : f(P[p]); }
void in()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i(1), x; i <= n; i++)
		for (int j(1); j <= n; j++)
		{
			cin >> x;
			if (i < j) Eg.push_back({ i, j, x });
		}
	sort(Eg.begin(), Eg.end());
}
void sv()
{
	iota(P, P + 2501, 0);
	for (auto& [p, q, w] : Eg)
	{
		int x(f(p)), y(f(q));
		if (x ^ y)
			(x > y ? P[x] = y : P[y] = x), cout << p << ' ' << q << '\n';
	}
}
int main()
{
	in();
	sv();
}
