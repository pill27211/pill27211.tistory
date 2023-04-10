#include<bits/stdc++.h>
#define ll long long
using namespace std;

priority_queue <ll> Q, an;
ll n, q, i;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	for(cin >> n >> q; n--;)
		cin >> i, Q.push(-i);
	for(int x, y; q--;)
	{
		while(Q.size() && !Q.top()) an.push(0), Q.pop();
		cin >> x >> y;
		if(y ^ 1)
		{
			queue <ll> t;
			while(Q.size() && -Q.top() <= x) t.push(Q.top()), Q.pop();
			while(t.size()) Q.push(t.front() * y), t.pop();
		}
	}
	while(Q.size()) an.push(Q.top()), Q.pop();
	while(an.size()) cout << -an.top() << ' ', an.pop();
}
