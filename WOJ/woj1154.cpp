/*
    Name: 
    Copyright: 
    Author: 
    Date: 13/01/16 17:35
    Description: woj1154 
*/
#include<iostream>
#include<stdio.h>
#include<ctype.h>
#include<string> 
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    string str;
    int count=0;
    while(getline(cin,str)&&str!="#")
    {
        count++;
        cout<<"Case "<<count<<": ";
        for(int i=0;i<str.length();++i)
        {
            if((i+1)%2==0)
                str[i]=toupper(str[i]);
        }
        cout<<str<<endl;
    }
    count=0;
    return 0;
}