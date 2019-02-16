/*
    Name: 
    Copyright: 
    Author: 
    Date: 13/01/16 19:55
    Description: woj1203 
*/
#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    vector<int> v;
    int n,num;
    while(scanf("%d",&n)!=EOF)
    {
        v.clear();
        for(int i=0;i<n;++i)
        {
            scanf("%d",&num);
            v.push_back(num);
        }
        sort(v.begin(),v.end());
        printf("%d\n",v[n/2]);
    }
    return 0;
}