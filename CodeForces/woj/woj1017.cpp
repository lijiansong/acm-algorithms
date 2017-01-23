/*
    Name: 
    Copyright: 
    Author: 
    Date: 28/12/15 09:30
    Description: woj1017
    其实就是一个数学题，最终的结果就是
    2.0*b*c*(1-cosA*cosA)/a;
*/
#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
double GetStrength(int x0,int y0,int x1,int y1)
{
    return sqrt(fabs(x0-x1)*fabs(x0-x1)+fabs(y0-y1)*fabs(y0-y1));
}
double GetAnswer(int x0, int y0, int x1, int y1, int x2, int y2)
{
    double a,b,c,cos_A;
    a=GetStrength(x0,y0,x1,y1);
    b=GetStrength(x0,y0,x2,y2);
    c=GetStrength(x1,y1,x2,y2);
    cos_A=(b*b+c*c-a*a)/(2.0*b*c);
    return 2.0*b*c*(1-cos_A*cos_A)/a;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    while(cin>>n&&n!=0)
    {
        double answer[n];
        for(int i=0;i<n;i++)
        {
            int temp[3][2];
            for(int j=0;j<3;j++)
                cin>>temp[j][0]>>temp[j][1];
            answer[i]=GetAnswer(temp[0][0],temp[0][1],temp[1][0],temp[1][1],temp[2][0],temp[2][1]);
            printf("%4.3f\n", answer[i]);
        }
    }
    return 0;
}