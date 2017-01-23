/*
    Name: 
    Copyright: 
    Author: 
    Date: 13/01/16 20:18
    Description: woj1204 
*/
#include<iostream>
#include<stdio.h>
//#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    //vector<int> v;
    
    int n,*num,ans;
    while(scanf("%d",&n)!=EOF)
    {
        num=new int[n];
        for(int i=0;i<n;++i)
        {
            scanf("%d",&num[i]);
        }
        sort(num,num+n);
        if(n%2==1)
            ans=num[n/2];
        else
        {
            int mid=n/2;
            if(num[mid-1]==num[mid])
                ans=num[mid];
            else if(num[0]==num[mid-1])
                ans=num[mid-1];
            else if(num[mid]==num[n-1])
                ans=num[mid];
        }
        printf("%d\n",ans);
        delete num;
    }
    return 0;
}