/*
    Name: 
    Copyright: 
    Author: 
    Date: 14/01/16 18:22
    Description: woj1372 
*/
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m,a[100001];
    memset(a,0,sizeof(a));
    while(cin>>n>>m&&(n!=0&&m!=0))
    {
        for(int i=0;i<n;++i)
            cin>>a[i];
        sort(a,a+n);
        for(int j=0;j<n;j+=m)
        {
            if(j==0)
                cout<<a[j];
            else
                cout<<" "<<a[j];
        }
        cout<<endl;
    }
    return 0;
}