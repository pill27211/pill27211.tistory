#include <bits/stdc++.h>
using namespace std;

int n, m, k, r, dp[1001][1001];
int main()
{
    cin >> n >> m;
    for(int i(1); i <= n; i++)
        for(int j(1); j <= m; j++)
        {
            scanf("%d", &k);
            if(!k)
                dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1, r = max(r, dp[i][j]);
        }
    cout << r;
}
