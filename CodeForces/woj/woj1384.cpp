/*
    Name: 
    Copyright: 
    Author: 
    Date: 19/01/16 23:05
    Description: woj1384 
*/
#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    long long num,n,m,sum=0,count;
    int index=1;
    scanf("%lld",&num);
    while(num--)
    {
        //cin>>n>>m;
        scanf("%lld%lld",&n,&m);
        sum=(m+n)*(m-n+1)/2;
        printf("Case #%d: %lld\n",index,sum);
        index++;
    }
    index=1;
    return 0;
}