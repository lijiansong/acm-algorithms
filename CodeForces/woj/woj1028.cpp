/*
	Name: 
	Copyright: 
	Author: 
	Date: 23/01/16 16:12
	Description: woj1028
*/
#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
	freopen("in.txt","r",stdin);
	int t,n,x1,y1,x2,y2,diff,count=1;;
	cin>>t;
	while(t--)
	{
		cout<<"Case "<<count<<":"<<endl;
		cin>>n>>x1>>y1>>x2>>y2;
		if((y1-y2+x1-x2)%2!=0)
		{
			cout<<"-1"<<endl;
		}
		else
		{
			if(fabs(y1-y2)<=fabs(x1-x2))
				diff=fabs(x1-x2);
			else
				diff=fabs(y1-y2);
				cout<<diff<<endl;
		}
		if(t)
			cout<<endl;
		count++;
	}
	count=1;
	return 0;
}

