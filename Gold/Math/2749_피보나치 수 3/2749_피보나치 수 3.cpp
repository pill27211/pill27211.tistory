#include<stdio.h>

long long n, i, a[1500001] = { 0, 1 };
int main()
{
    scanf("%lld", &n);
    for (i = 0; i < 1500000; i++)
        a[i + 2] = (a[i + 1] + a[i]) % 1000000;
    printf("%lld", a[n % 1500000]);
}
