/*
    Name: 
    Copyright: 
    Author: LJS
    Date: 01/10/15 22:24
    Description: woj1046-simple
*/
#include<iostream>
using namespace std;
int main()
{
    int *array;
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        array=new int[n];
        for(int i=0;i<n;i++)
            cin>>array[i];
        int ans=0;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                ans=(array[i]>array[j])?ans+1:ans;
        if(t==0)
            cout<<ans;
        else
            cout<<ans<<endl;
    }
    return 0;
}