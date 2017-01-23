/*
    Name: 
    Copyright: 
    Author: 
    Date: 14/01/16 16:33
    Description: woj1171 
*/
#include<iostream>
#include<stdio.h>
using namespace std;
int w[21][21][21];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int a,b,c,n,ans;
    for(int i = 0; i <= 20; ++i) 
    {
        for(int j = 0; j <= 20; ++j) 
        {
            for(int k = 0; k <= 20; ++k) 
            {
                if(i == 0 || j == 0 || k == 0)
                {
                    w[i][j][k] = 1;
                }
            }
        }
    }
    for(int i = 0; i <= 20; ++i) 
    {
        for(int j = 0; j <= 20; ++j)
        {
            for(int k = 0; k <= 20; ++k)
            {
                if(i > 0 && j > 0 && k > 0) 
                {
                    if(i < j && j < k) 
                    {
                        w[i][j][k] = w[i][j][k-1] + w[i][j-1][k-1] - w[i][j-1][k];
                    }
                    else 
                    {
                        w[i][j][k] = w[i-1][j][k] + w[i-1][j-1][k] + w[i-1][j][k-1] - w[i-1][j-1][k-1];
                    }
                }
            }
        }
    }
    cin>>n;
    while(n--)
    {
        cin>>a>>b>>c;
        printf("W(%d, %d, %d) = ",a,b,c);
        if(a <= 0 || b <= 0 || c <= 0) 
        {
            a = b = c = 0;
        }
        if(a > 20 || b > 20 || c > 20) 
        {
            a = b = c = 20;
        }
        ans=w[a][b][c];
        printf("%d\n",ans);
    }
    return 0;
}