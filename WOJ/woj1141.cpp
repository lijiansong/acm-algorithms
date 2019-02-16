/*
    Name: 
    Copyright: 
    Author: 
    Date: 13/01/16 15:32
    Description: woj1141 
*/
#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    char list[27],listLower[27],listKey[27];
    for(int i=0; i<26; ++i)
        list[i]= 65 + i;
    list[26]='\0';
    for(int i=0; i<26; ++i)
        listLower[i]=list[i]+32;
    listLower[26]='\0';
    string key;
    while(cin>>key)
    {
        int keyLen=key.length();
        for(int i=0; i<keyLen;i++) 
          listKey[i]=key[i];
        for(int i=25,j=keyLen; i>=0; --i)
        {
              string::size_type pos = key.find(list[i]);
              if(pos == string::npos)
              {
                  listKey[j]=list[i];
                  j++;
              }
        }
        listKey[26]='\0';
        string str;
        bool first=true;
        while(getline(cin,str))
        {
            string strListKey = listKey;
              for(int i=0; str[i]!='\0'; ++i)
              {
                  if(str[i]>96 && str[i]<123)
                  {
                      string::size_type pos = strListKey.find(str[i]-32);
                      cout<<listLower[pos];
                  }
                  else if(str[i]>64 && str[i]<91)
                  {
                      string::size_type pos = strListKey.find(str[i]);
                      cout<<list[pos];
                  }
                  else
                      cout<<str[i];
              }
              if(!first)
              cout<<endl;
              first=false;
        }
    }
    return 0;
}