/*
    Name: 
    Copyright: 
    Author: 
    Date: 16/01/16 19:10
    Description: woj1173
    ‘º…™∑ÚŒ Ã‚,µ›πÈ 
*/
#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    int n,m;
    while(cin>>n>>m&&(n!=0&&m!=0))
    {
        int ans=0,i;
        for(i=2;i<=n;++i)
            ans=(ans+m)%i;
        cout<<ans+1<<endl;
    }
    return 0;
}