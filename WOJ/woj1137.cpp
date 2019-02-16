/*
    Name: 
    Copyright: 
    Author: 
    Date: 12/01/16 16:56
    Description: woj1137
*/
#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n=0,m=0,min_price;
    while(cin>>n>>m)
    {
        int *price=new int[n];
        for(int i=0;i<n;i++)
            cin>>price[i];
        min_price=price[0];
        for(int i=1;i<n;i++)
            min_price=(min_price<price[i])?min_price:price[i];
        int num=m/min_price;
        cout<<num<<endl; 
        delete price;
    }
    return 0;
}