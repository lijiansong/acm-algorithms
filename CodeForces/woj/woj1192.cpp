/*
    Name: 
    Copyright: 
    Author: 
    Date: 13/01/16 19:08
    Description: woj1192 
*/
#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    vector<int> v;
    while(cin>>n)
    {
        v.clear();
        int *image=new int[n*n];
        for(int i=0;i<n*n;++i)
        {
            cin>>image[i];
            int count=0;
            for(int j=image[i];j;j=j/2)
            {
                if(j%2)
                    count++; 
            }
            if(count%2)
                v.push_back(1);
            else
                v.push_back(0); 
        }
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                if((i*n+j+1)%n==0)
                    cout<<v[i*n+j]<<endl;
                else
                    cout<<v[i*n+j]<<" ";
            }
                
        }
    }
    return 0;
}