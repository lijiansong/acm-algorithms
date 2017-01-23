/*
	Name: 
	Copyright: 
	Author: 
	Date: 23/01/16 15:00
	Description: woj1413
*/
#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	freopen("in.txt","r",stdin);
	int t;
	double ans=0,a,b,h;
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>h;
		ans=h*b/a;
		printf("%.2lf\n",ans);
	}
	return 0;
}
