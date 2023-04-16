#include<bits/stdc++.h>
using namespace std;

priority_queue <int> Q;
int n, m, r;

int main()
{
	cin >> n >> m;
	for (int i, s{}; n--;)
	{
		scanf("%d", &i);
		Q.push(i); s += i;
		while (s >= m) r++, s -= Q.top() * 2, Q.pop();
	}
	cout << r;
}
