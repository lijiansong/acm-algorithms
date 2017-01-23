#include<cstdio>
#include<cstring>
bool f[10000000];
int r[500001];
int main()
{
    int n,i;
    memset(f,true,sizeof(f));
    r[0]=0;
    for(i=1;i<=500000;i++)
    {
        if(r[i-1]>i&&f[r[i-1]-i])r[i]=r[i-1]-i;
        else r[i]=r[i-1]+i;
        f[r[i]]=false;
    }
    while(scanf("%d",&n)&&n!=-1)
        printf("%d\n",r[n]);
    return 0;
}