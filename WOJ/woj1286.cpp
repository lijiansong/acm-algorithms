/*
    Name: 
    Copyright: 
    Author: 
    Date: 14/01/16 22:50
    Description: woj1286
*/
#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
double ratio (int x1,int y1,int z1,int x2,int y2,int z2,int x3,int y3,int z3) 
{
    double ab,bc,ac; 
    double p,S;
    double r,R;
    ab=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2)); 
    bc=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2)+(z3-z2)*(z3-z2)); 
    ac=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3)+(z1-z3)*(z1-z3)); 
    p=(ab+bc+ac)/2;
    S=sqrt(p*(p-ab)*(p-bc)*(p-ac));
    r=2*S/(ab+bc+ac);
    R=ab*bc*ac/4/S;
    return (r*r)/(R*R);
} 
int main()
{
    //freopen("in.txt","r",stdin);
    int x1,y1,z1,x2,y2,z2,x3,y3,z3;
    double ans;
    while(cin>>x1>>y1>>z1>>x2>>y2>>z2>>x3>>y3>>z3)
    {
        ans=ratio(x1,y1,z1,x2,y2,z2,x3,y3,z3);
        printf("%.3lf\n",ans);
    }
    return 0;
}