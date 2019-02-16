/*
    Name: 
    Copyright: 
    Author: 
    Date: 13/01/16 17:18
    Description: woj1143
*/

#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int m,p,n,sum;
    while(cin>>m>>p>>n&&(m!=0&&p!=0&&n!=0))
    {
        if(p*n<m)
            cout<<m<<endl;
        else
            cout<<p*n<<endl;
    }
    return 0;
}