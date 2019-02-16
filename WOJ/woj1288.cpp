/*
    Name: 
    Copyright: 
    Author: 
    Date: 15/01/16 08:50
    Description: woj1288 
*/
#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    int t,k;
    string a,b;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>k;
        int len=a.length();
        int *temp=new int[len];
        int ans=0;
        for(int i=0;i<len;++i)
        {
            temp[i]=((b[i]>a[i])?(b[i]-a[i]):(a[i]-b[i]));
            ans+=temp[i];
        }
        sort(temp,temp+len);
        for(int i=len-1;i>len-1-k;--i)
        {
            ans-=(temp[i]==0)?-1:temp[i];
        } 
        cout<<ans<<endl;
        delete temp;
    }
    return 0;
}