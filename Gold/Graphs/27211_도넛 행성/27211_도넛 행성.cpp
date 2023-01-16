#include <bits/stdc++.h>
using namespace std;

int dy[]{-1, 1, 0, 0}, dx[]{0, 0, -1, 1};
int M[1001][1001], V[1001][1001];
int n, m, i, j, r;

void f(int p, int q)
{
    queue <pair<int, int>> Q;
    Q.push({p, q});
    V[p][q] = 1;
    while(Q.size())
    {
        auto [a, b] = Q.front(); Q.pop();
        for(int k = 0; k < 4; k++)
        {
            p = a + dy[k];
            q = b + dx[k];
            if(p >= -1 && q >= -1 && p <= n && q <= m)
            {
                if(p == -1 || p == n)
                    p = p == -1 ? n - 1 : 0;
                if(q == -1 || q == m)
                    q = q == -1 ? m - 1 : 0;
                if(!M[p][q] && !V[p][q])
                    V[p][q] = 1, Q.push({p, q});
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(; i < n; i++)
        for(j = 0; j < m; cin >> M[i][j++]);
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            if(!M[i][j] && !V[i][j])
                r++, f(i, j);
    cout << r;
}
