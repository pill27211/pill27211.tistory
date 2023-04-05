#include<bits/stdc++.h>
using namespace std;

long long n, i, j, r;

int main()
{
	cin >> n; n--;
	for (i = 1; i <= n; i = j + 1)
		j = n / (n / i), r += n / i * (j - i + 1);
	cout << r + n + 1;
}
