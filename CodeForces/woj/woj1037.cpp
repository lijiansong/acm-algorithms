/*
    Name: 
    Copyright: 
    Author: 
    Date: 14/01/16 13:03
    Description: woj1037 
*/
#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n=0,sum=0;
    while(cin>>n&&n)
    {
        int *c=new int[n];
        int *d=new int[n];
        for(int i=0;i<n;++i)
            cin>>c[i];
        for(int i=0;i<n;++i)
            cin>>d[i];
        for(int i=0;i<n;++i)
        {
            sum=sum+c[i]-d[i];
        }
        if(sum>=0)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
        delete c;
        delete d;
        sum=0;
    }
    return 0;
}