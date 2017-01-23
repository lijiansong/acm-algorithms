/*
    Name: 
    Copyright: 
    Author: 
    Date: 13/01/16 17:51
    Description: woj1162
    经典问题，大数和 
*/
#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
string Add(string a,string b)
{
    if(a.length()<b.length())
    {
        string temp=a; a=b; b=temp;
    }
    int i,j;
    for(i=a.length()-1,j=b.length()-1;i>=0;i--,j--)
    {
        a[i]=(a[i]+(j>=0?b[j]-'0':0));
        if(a[i]>'9')
        {
            a[i] -=10;
            if(i) a[i-1]++;
            else a='1'+a;
        }
    }
    return a;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    string num1,num2,ans;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>num1>>num2;
        ans=Add(num1,num2);
        cout<<ans<<endl;
    }
    return 0;
}