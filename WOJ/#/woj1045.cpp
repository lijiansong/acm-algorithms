/*
    Name: 
    Copyright: 
    Author: LJS
    Date: 01/10/15 22:24
    Description: woj1035-simple
*/
#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    string s;
    getline(cin,s);
    for(int i=0;i<t;i++)
    {
        getline(cin,s);
        if(s[0]>='a'&&s[0]<='z')
            s[0]=s[0]-32;
        for(int j=1;j<s.size();j++)
        {
            if(s[j]>='A'&&s[j]<='Z'&&s[j-1]!=' ')
                s[j]=s[j]+32;
        }
        cout<<s<<endl;
    }
    return 0;
}