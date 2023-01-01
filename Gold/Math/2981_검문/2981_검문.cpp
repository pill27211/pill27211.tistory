#include<bits/stdc++.h>
using namespace std;

vector <int> V;
int n, i, k, p, q;

int main()
{
	cin >> n >> p; n--;
	while (n--)
		cin >> q, k = gcd(k, abs(q - p)), p = q;
	for (V.push_back(k), i = 2; i * i <= k; i++)
		if (!(k % i))
			V.push_back(i), V.push_back(k / i);

	V.erase(unique(V.begin(), V.end()), V.end());
	sort(V.begin(), V.end());
	for (int i : V)
		cout << i << ' ';
}
