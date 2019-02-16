/*
    Name: 
    Copyright: 
    Author: 
    Date: 13/01/16 14:34
    Description: woj1119
    纯粹的数学题 
*/
#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    double d,h,alpha,beta,gamma,tan_alpha,tan_beta,tan_gamma,ans;
    const double pi=3.141592653;
    cin>>d>>h;
    while(cin>>alpha>>beta>>gamma&&alpha&&beta&&gamma)
    {
        tan_alpha=tan(alpha/180.0*pi);
        tan_beta=tan(beta/180.0*pi);
        tan_gamma=tan(gamma/180.0*pi);
        ans=d*sqrt(2.0/(1.0/tan_alpha/tan_alpha+1.0/tan_gamma/tan_gamma-2.0/tan_beta/tan_beta))+h;
        if(ans-(int)ans<0.5)
            cout<<(int)ans<<endl;
        else
            cout<<(int)ans+1<<endl;
    }
    return 0;
}