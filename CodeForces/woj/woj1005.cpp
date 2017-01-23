/*
    Name: 
    Copyright: 
    Author: 
    Date: 29/12/15 03:26
    Description: WOJ1005
    典型的动态规划 
*/
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,size,s[101],point[101],dp[100001],i,j;
    memset(s,0,sizeof(s));
    memset(point,0,sizeof(point));
    while(cin>>n)
    {
        for(i=0;i<n;i++)
        {
            cin>>s[i]>>point[i];
        }
        cin>>size;
        memset(dp,0,sizeof(dp));
        for(i=0;i<n;i++)
            for(j=size;j>=0;j--)
            {
                if(j-s[i]>=0)
                    dp[j]=max(dp[j],dp[j-s[i]]+point[i]);
            }
        cout<<dp[size]<<endl;
    }
    return 0;
}