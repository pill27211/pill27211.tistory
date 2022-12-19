#include<bits/stdc++.h>
#define ll long long
#define P pair<ll, ll>
using namespace std;

vector <P> Vx;
vector <P> Vy;
vector <P> V[400001];
ll D[400001];
ll N, K, i, j;
ll x, y, z, p, q;

void f1()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	fill(D, D + 400001, 1e18);
	cin >> N >> K;

	for (i = 1; i <= N; i++)
	{
		cin >> x >> y >> z;

		Vx.push_back({ x, i });
		Vy.push_back({ y, i });

		p = z % K;
		q = (K - p) % K;
		V[i].push_back({ N + 1 + p, z });
		V[N + 1 + q].push_back({ i, z });
	}
}
void f2()
{
	priority_queue <P> Q;
	Q.push({ 0, 1 });
	D[1] = 0;

	while (!Q.empty())
	{
		i = -Q.top().first;
		j = Q.top().second;
		Q.pop();

		if (D[j] < i)
			continue;
		for (int k = 0; k < (int)V[j].size(); k++)
		{
			ll d = i + V[j][k].second;
			if (d < D[V[j][k].first])
			{
				D[V[j][k].first] = d;
				Q.push({ -d, V[j][k].first });
			}
		}
	}
}
void f3()
{
	sort(Vx.begin(), Vx.end());
	sort(Vy.begin(), Vy.end());

	for (i = 1; i < N; i++)
	{
		V[Vx[i].second].push_back({ Vx[i - 1].second, abs(Vx[i].first - Vx[i - 1].first) });
		V[Vx[i - 1].second].push_back({ Vx[i].second, abs(Vx[i].first - Vx[i - 1].first) });
		V[Vy[i].second].push_back({ Vy[i - 1].second, abs(Vy[i].first - Vy[i - 1].first) });
		V[Vy[i - 1].second].push_back({ Vy[i].second, abs(Vy[i].first - Vy[i - 1].first) });
	}
	f2();
}
int main(void)
{
	f1();
	f3();
	for (i = 1; i <= N; i++)
		cout << D[i] << '\n';
}
