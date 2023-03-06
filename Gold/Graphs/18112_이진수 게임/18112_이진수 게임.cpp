#include<bits/stdc++.h>
using namespace std;

queue <pair<int, int>> Q;
string a, b;
int p, q, V[1 << 10];

void in()
{
	cin >> a >> b;
	for (int i{}, l(a.size()); i < l; i++)
		if (a[i] & 1)
			p |= (1 << (l - i - 1));
	for (int i{}, l(b.size()); i < l; i++)
		if (b[i] & 1)
			q |= (1 << (l - i - 1));
	V[p] = 1, Q.push({ p, 0 });
}
void sv()
{
	while (Q.size())
	{
		auto [t, c](Q.front()); Q.pop();
		if (t == q) cout << c, exit(0);
		for (int i{}, x(t); x >> 1; x >>= 1)
			if (!V[p = t ^ (1 << i++)])
				V[p] = 1, Q.push({ p, c + 1 });
		if (t && !V[t - 1]) V[t - 1] = 1, Q.push({ t - 1, c + 1 });
		if (t + 1 < (1 << 10) && !V[t + 1]) V[t + 1] = 1, Q.push({ t + 1, c + 1 });
	}
}
int main()
{
	in();
	sv();
}
