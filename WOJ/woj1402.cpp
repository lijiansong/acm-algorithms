/*
    Name: 
    Copyright: 
    Author: 
    Date: 05/01/16 13:44
    Description: woj1402
*/
#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
int GetArea(double num[][2],int no)
{
    double area=0;
    for(int i=0;i<no;++i)
    {
        area+=(num[(i+1)%no][0]-num[i][0])*(num[(i+1)%no][1]+num[i][1])/2;
    }
    area=fabs(area);
    int change=int(area);
    if((area-change)>0.5)
        change++;
    return change;
}
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int k;
    while(cin>>k&&k!=0)
    {
        double num[100][2];
        for(int i=0;i<k;i++)
            cin>>num[i][0]>>num[i][1];
        cout<<GetArea(num,k)<<endl;
    }
    return 0;
}