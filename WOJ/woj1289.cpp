/*
    Name: 
    Copyright: 
    Author: 
    Date: 14/01/16 12:33
    Description: woj1289 
*/
#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    string str1,str2;
    char map[]={'A','T','C','G'};
    int count=0;
    while(cin>>str1>>str2&&str1!="#")
    {
        for(int i=0;i<str1.length();++i)
        {
            if(str1[i]==str2[i])
                count++;
            else
            {
                if((str1[i]=='A'||str1[i]=='T')&&(str2[i]=='C'||str2[i]=='G'))
                    count++;
                else if((str1[i]=='C'||str1[i]=='G')&&(str2[i]=='A'||str2[i]=='T'))
                    count++;
            }
        }
        cout<<count<<endl;
        count=0;
    }
    return 0;
}