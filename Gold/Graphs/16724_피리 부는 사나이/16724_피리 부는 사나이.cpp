#include<bits/stdc++.h>
using namespace std;

map <char, pair <int, int>> M{{'U', {-1, 0}}, {'D', {1, 0}}, {'L', {0, -1}}, {'R', {0, 1}}};
char a[1001][1001];
int n, m, r, i, j, k, v[1001][1001];

int f(int p, int q)
{
    v[p][q] = k;
    p += M[a[p][q]].first, q += M[a[p][q]].second;
    return v[p][q] ? v[p][q] == k : f(p, q);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(; i < n; i++)
        for(j = 0; j < m; cin >> a[i][j++]);
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            if(!v[i][j])
                k++, r += f(i, j);
    cout << r;
}
