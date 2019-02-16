/*
	Name: 
	Copyright: 
	Author: 
	Date: 23/01/16 17:38
	Description: woj1313
*/
#include<iostream>
#include<stdio.h>
using namespace std;
int Find_K(int k)
{
    int ans[1000]={0};
    int count = 0,s = 1;  
    while(s < 1000)  
    {
        s *= k;
        count++;
    }
    s %= 1000;
    k %= 1000;
    ans[s] = count;  
    while(true)   
    {  
        s = s * k % 1000;
        count++;
        if(!ans[s]) 
			ans[s] = count;
        else 
			return ans[s] + count;
    }
}
int main()
{
	freopen("in.txt","r",stdin);
	int n;
	while(cin>>n&&n)
	{
		cout<<Find_K(n)<<endl;
	}
	return 0;
}

