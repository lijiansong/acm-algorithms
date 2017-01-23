/*
    Name: 
    Copyright: 
    Author: 
    Date: 27/12/15 05:38
    Description: woj1170
    用STL中的map投机取巧 试一下 
*/
#include<iostream>
#include<map>
#include<stdio.h>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    map<int , int> m ;
    map<int , int> :: iterator i;
    int x ;
    while(scanf("%d",&x) == 1 ) 
    {
        if (x == 0) 
            break ;
        m.insert(pair<int , int> (x,1));
    }
    for (i = m.begin() ; i != m.end() ; i ++)
        cout<<i -> first<<" ";
    return 0 ;
}