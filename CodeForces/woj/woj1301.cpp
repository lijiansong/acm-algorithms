/*
    Name: 
    Copyrighight: 
    Authighor: 
    Date: 14/01/16 19:17
    Description: woj1301 
*/
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int m,n,s;
    cin>>m;
    while(m--)
    {
        cin>>n>>s;
        int *a=new int[n];
        for(int i = 0; i < n; ++i) 
        {
            cin>>a[i];
        }
        int low = -1, high = 0,count = n + 1,sum = a[0];
        while(low < n && high < n) 
        {
            if(sum < s) 
            {
                ++high;
                sum += a[high];
            } 
            else
            {
                if(count > high - low) 
                {
                    count = high - low;
                }
                sum -=a[low+1];
                ++low;
            }
        }
        if(count == n + 1) 
            count = 0;
        cout<<count<<endl;
        delete a;
    }
    return 0;
}