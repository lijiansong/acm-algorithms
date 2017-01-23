/*
    Name: 
    Copyright: 
    Author: 
    Date: 16/01/16 19:50
    Description: woj1294 
*/
#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    int a[31]={0};
    a[2]=2;
    a[3]=2;
    int t,n,half,s;
    cin>>t;
    while (t--)
    {
        cin>>n;
        half = 2*n;
        for (int i=4;i<=half;i++)
            a[i]=a[i-1] + 2*a[i-2];
        s = 3*a[half]/2 + a[half - 1];
        cout<<s<<endl;
    }
    return 0;
}