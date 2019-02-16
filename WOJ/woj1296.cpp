/*
    Name: 
    Copyright: 
    Author: 
    Date: 14/01/16 22:10
    Description: woj1296 
*/
#include<iostream>
using namespace std;
int main()
{
    int n;
    while(cin>>n&&n)
    {
        if(n%2==0)
        {
            cout<<"No Solution!"<<endl;
        }
        else
            cout<<n-1<<endl;
    }
    return 0;
}