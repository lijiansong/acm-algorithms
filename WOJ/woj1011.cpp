/*
    Name: 
    Copyright: 
    Author: 
    Date: 05/01/16 13:44
    Description: woj1011
*/
#include<stdio.h>
#include<iostream>
using namespace std;
long long  combin(long long  n, long long  k){
    long long  a=1, b=1,c=1;
    if (k > n - k)  k = n - k;
    for(long long i=1;i<=k;++i)
        a *= n+1-i;
    for(long long i=1;i<=k;++i)
        b *= i;
    return a/b;
}

long long  F(long long  n){
    if (n == 0)
        return 1;
    if (n >= 0 && n <= 3)
        return 1;
    long long  x = n/ 3;
    long long  ans = 0;
    for(long long i=1;i<=x;++i)
        ans += F(3 * i - 1)*F(n - 3 * i)*combin(n - 1, 3 * i - 1);
    if (n % 3 == 2)
        ans += F(n - 1);
    return ans;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    long long  n;
    while (cin>>n)
    {
        if (!n)
            cout << 0 << endl;
        else
        {
            long long answer = F(n);
            cout << answer << endl;
        }
    }
}