/*
    Name: 
    Copyright: 
    Author: 
    Date: 13/01/16 23:31
    Description: woj1206 
    Õ·×ªÏà³ý 
*/
#include<iostream>
#include<stdio.h>
using namespace std;
int func(int a,int b)
{
    /*int temp,r;
    if(a<b)
    {
        temp=a;
        a=b;
        b=temp;
    }
    r=a%b;
    while(r)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return b;*/
    return b?func(b,a%b):a;
} 
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int a,b,n;
    while(cin>>a>>b>>n)
    {
        if(a==0&&b==0)
        {
            if(n!=0)
                cout<<"Impossible!"<<endl;
            else
                cout<<"Possible!"<<endl;
        }
        else
        {
            if(n%func(a,b)==0)
                cout<<"Possible!"<<endl;
            else
                cout<<"Impossible!"<<endl;
        }
    }
    return 0;
}