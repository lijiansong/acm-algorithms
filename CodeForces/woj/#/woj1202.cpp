#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[2*n+1];
    for (int i=0;i<=2*n;i++)  scanf("%d",&a[i]);
    int dif = a[0];
    for (int i=1;i<=2*n;i++)  dif ^= a[i];
    printf("%d\n",dif);
    return 0;
    }