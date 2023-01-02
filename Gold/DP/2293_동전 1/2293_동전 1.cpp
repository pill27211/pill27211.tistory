#include<stdio.h>

int a[100], d[10001] = {1};
int n, k, i, j;

int main()
{
	scanf("%d %d", &n, &k);
	for(i = 0; i < n; scanf("%d", &a[i++]));
	for(i = 0; i < n; i++)
	    for(j = a[i]; j <= k; j++)
	        d[j] += d[j - a[i]];
	printf("%d", d[k]);
}
