/*
    Name: 
    Copyright: 
    Author: 
    Date: 21/01/16 15:57
    Description: woj1302 
    a ^ b mod c = ((a ^ (b / 2) mod c) * (a ^ (b - b / 2) mod c)) mod c
*/
#include<iostream>
#include<stdio.h>
using namespace std;
/*int mod(int a,int b,int c)
{
    int digit[32];
    int i=0,k,result=1;
    while(b)//b转换为二进制 
    {
        digit[i++]=b%2;
        b>>=1;
    }
    for(k=i-1;k>=0;k--)
    {
        result=(result*result)%c;
        if(digit[k]==1)
        {
            result=(result*a)%c;
        }
    }
    return result;
}*/
long long mod(long long a, int b, int k)
{
    long long tmp = a, ret = 1;
    while (b)
    {
        if (b & 1)
            ret = ret * tmp % k;
        tmp = tmp * tmp % k;
        b >>= 1;
    }
    return ret;
}
int main()
{
    //freopen("in.txt","r",stdin);
    int z;
    scanf("%d",&z);
    int m,h,ans=0;
    while(z--)
    {
        scanf("%d %d",&m,&h);
        int *a=new int[h];
        int *b=new int[h];
        int *res=new int[h];
        for(int i=0;i<h;++i)
        {
            scanf("%d %d",&a[i],&b[i]);
            res[i]=mod(a[i],b[i],m);
        }
        ans=0;
        for(int i=0;i<h;++i)
        {
            ans=(ans+res[i])%m;
        }
        printf("%d\n",ans);
        //ans=0;
        delete a,b,res;
    }
    return 0;
}