#include <bits/stdc++.h>
using namespace std;
#define ll long long

map <ll, ll> M;
ll a, b, m = (ll)1e9 + 7;

ll f(ll n)
{
    if(!M.count(n))
    {
        ll p = f(n / 2 + (n & 1 ? 1 : -1)), q = f(n >> 1);
        M[n] = (n & 1 ? (p * p + q * q) : ((2 * p + q) * q)) % m;
    }
    return M[n];
}
int main()
{
    M[0] = 0; M[1] = 1;
    cin >> a >> b;
    cout << f(gcd(a, b));
}
