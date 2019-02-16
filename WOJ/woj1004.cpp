/*
    Name: 
    Copyright: 
    Author: 
    Date: 30/12/15 23:36
    Description: woj1004
    µ•ŒªªªÀ„ 
*/
#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    double num[3],temp,diff=0.0000001;
    char measurement[3][10];
    int i,j;
    while(cin>>temp)
    {
        num[0]=temp;
        cin>>measurement[0];
        for(i=1;i<3;i++)
        {
            cin>>num[i];
            cin>>measurement[i];
        }
        for(i=0;i<3;i++)
        {
            if(strcmp(measurement[i],"inches") == 0)
                num[i] *= 2.54;
            else if(strcmp(measurement[i],"centimeters") == 0)
                num[i] *= 1;
            else if(strcmp(measurement[i],"meters")==0)
                num[i] *= 100;
            else if(strcmp(measurement[i],"feet")==0)
                num[i] *= 30.48;
            else if(strcmp(measurement[i],"cubits") == 0)
                num[i] *= 45.72;
        }
        if((num[0] - num[1]) < diff&&(num[0] - num[1]) > -1*diff)
            cout<<"Spin"<<endl;
        else if(((num[0]-6*num[1])) < diff && ((num[0]-6*num[1])) > -1*diff )
            cout<<"Excellent"<<endl;
        else
            cout<<"Neither"<<endl;
            cout<<endl;
    }
    return 0;
}