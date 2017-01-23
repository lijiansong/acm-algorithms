/*
    Name: 
    Copyright: 
    Author: 
    Date: 28/12/15 03:30
    Description: woj1142
    ans[n]=2*ans[n-1]+1
    ans[0]=1
    ∴ans[n]=2^(n+1)-1 
    经典问题，大整数幂乘 
*/
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    char num[1000];
    int n,i,j,temp,carry;
    while(cin>>n)
    {
        memset(num,'\0',sizeof(num));
        num[0]='1';
        for(i=n;i>0;i--)
        {
            carry=0;
            j=0;
            while(num[j]!=0)
            {
                temp=(num[j]-'0')*2;
                num[j] = (temp%10)+'0'+carry;
                carry = temp/10;
                j++;  
            }
            if(carry!=0)
            {
                num[j]=carry+'0';
            }
            num[0]+=1;
        }
        for(i=strlen(num)-1;i>=0;i--)
        {
            j=num[i]-'0';
            cout<<j;
        }
        cout<<endl;
    } 
    return 0;
}