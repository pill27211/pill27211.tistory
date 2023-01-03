#include <bits/stdc++.h>
#define ll long long
using namespace std;

map <ll, ll> M;
ll a, m = (ll)1e9 + 7;

ll f(ll n)
{
    if (!M.count(n))
    {
        ll p = f(n / 2 + (n & 1 ? 1 : -1)), q = f(n >> 1);
        M[n] = (n & 1 ? (p * p + q * q) : ((2 * p + q) * q)) % m;
    }
    return M[n];
}
int main()
{
    M[0] = 0; M[1] = 1;
    cin >> a;
    cout << (f(a) * f(a + 1)) % m;
}
