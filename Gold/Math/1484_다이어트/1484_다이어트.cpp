#include<bits/stdc++.h>
using namespace std;

long long g, f, p(1), q(1);

int main()
{
	for(cin >> g; p < g;)
	{
		if(q * q - p * p == g) f = 1, cout << q << '\n';
		q * q - p * p <= g ? q++ : p++;
	}
	if(!f) cout << -1;
}
