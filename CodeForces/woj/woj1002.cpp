/*
  Name: 
  Copyright: 
  Author: 
  Date: 26/12/15 06:13
  Description: woj1002
  数各单词的首字母数得到的就是结果 
*/
#include<iostream>
using namespace std;
int main()
{
    string str;
    bool flag = false;    
    int count=0;
    while(cin >> str) 
    {
        if(str[0] == '1' || str[0] == '2') 
        {
            if(flag) 
              cout << count << endl;
            cout << str << " ";
            count = 0;
            flag = true;
        }
        else if((str[0] >= 'a' && str[0] <= 'z') || (str[0] >= 'A' && str[0] <= 'Z'))
            count++;
    }
    cout << count << endl;
    return 0;
}