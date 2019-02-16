/*
    Name: 
    Copyright: 
    Author: 
    Date: 14/01/16 21:06
    Description: woj1351 
*/
#include<iostream>
using namespace std;
int main() 
{
    //freopen("in.txt","r",stdin);
    int a[9] = {0,31,29,31,30,31,30,31,8};
    int num,month,day;
    cin>>num;
    while(num--)
    {
        cin>>month>>day;
        int ans = a[month] - day;
        for(int i = month + 1; i <=8; ++i) 
        {
            ans += a[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}