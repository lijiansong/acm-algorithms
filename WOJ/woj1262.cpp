/*
    Name: 
    Copyright: 
    Author: 
    Date: 16/01/16 19:42
    Description: woj1262 
*/
#include<iostream>
#include<stdio.h>
using namespace std;
int n;
int a[8][8];
int ans;
void  shift(int i)
{
    int temp;
    temp=a[i][n-1];
    int j;
    for(j=n-2;j>=0;j--)
        a[i][j+1]=a[i][j];
    a[i][0]=temp;
}
void get(int i)
{
    if (i==n)
    {
        int sum;
        int max;
        int j;
        max=0x80000000;
        for (i=0;i<n;i++)
        {
            sum=0;
            for (j=0;j<n;j++)
            {
                sum+=a[j][i];
            }
            if (sum>max)
            {
                max=sum;
            }
        }
        if(max<ans)
        {
            ans=max;
            return ;
        }
    }
    else
    {
        int k;
        for(k=0;k<n;k++)
        {
            shift(i);
            get(i+1);
        }
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    while(cin>>n&&(n!=-1))
    {
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                cin>>a[i][j];
            }
        }
        ans=0x7fffffff;
        get(0);
        cout<<ans<<endl;
    }
    return 0;
}