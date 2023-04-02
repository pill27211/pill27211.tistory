#include<bits/stdc++.h>
#define ll long long
using namespace std;

unordered_map <ll, ll> S;
queue <ll> Q;
ll n;

int main()
{
	cin >> n;
	Q.push(n), S[n] = 0;
	while (Q.size())
	{
		ll t(Q.front()); Q.pop();
		if (t == 1) cout << S[t], exit(0);
		if (!(t % 3) && !S.count(t / 3)) S[t / 3] = S[t] + 1, Q.push(t / 3);
		if (!(t & 1) && !S.count(t >> 1)) S[t >> 1] = S[t] + 1, Q.push(t >> 1);
		if (t && !S.count(t - 1)) S[t - 1] = S[t] + 1, Q.push(t - 1);
	}
}
