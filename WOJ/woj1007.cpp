/*
    Name: 
    Copyright: 
    Author: 
    Date: 02/01/16 22:51
    Description: woj1007 
    Ì°ÐÄ 
*/
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,i,j;
    while(cin>>n)
    {
        int time[8][n];
        for(i=0;i<8;i++)
            for(j=0;j<n;j++)
                cin>>time[i][j];
        int min[10001];
        memset(min,10001,sizeof(min));
        int total=0;
        for(j=0;j<n;j++)
        {
            for(i=0;i<8;i++)
                min[j]=min[j]<time[i][j]?min[j]:time[i][j];
            total+=min[j];
        }
        cout<<total<<endl;
    }
    return 0;
}