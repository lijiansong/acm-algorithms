/*
    Name: 
    Copyright: 
    Author: 
    Date: 14/01/16 17:18
    Description: woj1185
    组合数学经典问题
    http://blog.csdn.net/chlxyd/article/details/8723074
    直接查表 
*/
#include<iostream>
#include<stdio.h>
using namespace std;
/*
int f(int n, int m)
{
    if(m == 1 || n == 0)
        return 1;
    if(m > n)
        return f(n, n);
    return f(n, m-1) + f(n-m, m);
}
*/
long long f[101][101];
void func()
{
    //f[i][j]表示把i个球放进j个盒子里的方法总数
    f[0][0]=1;
    for(int i=1;i<101;++i)
    {
        for(int j=1;j<=i;++j)
        {
            if(i-j<=j)
            {
                f[i][j] = f[i][j-1] + f[i-j][i-j];
            }
            else
            {
                f[i][j] = f[i][j-1] + f[i-j][j];
            }
        }
    }
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int m,n;
    func();
    while(cin>>m>>n)
    {
        if(m<=n)
            cout<<f[m][m]<<endl;
        else
            cout<<f[m][n]<<endl;
    }
    return 0;
}