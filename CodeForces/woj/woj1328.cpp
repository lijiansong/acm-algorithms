/*
    Name: 
    Copyright: 
    Author: 
    Date: 14/01/16 20:08
    Description: woj1328 
*/
#include<iostream>
#include<string>
using namespace std;
int main() 
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    char correct[] = {'1','2','3','4','5','6','7','8','9','0','Q','W','E','R','T','Y',
            'U','I','O','P','A','S','D','F','G','H','I','J','K','L',';','Z',
            'X','C','V','B','N','M',',','.'};
    char error[] = {'2','3','4','5','6','7','8','9','0','-','W','E','R','T','Y','U',
            'I','O','P','[','S','D','F','G','H','I','J','K','L',';','\'','X',
            'C','V','B','N','M',',','.','/'};
    string str;
    int i,j;
    while(getline(cin,str)) 
    {
        for(i = 0; i < str.length(); ++i) 
        {
            for(j = 0; j < 40; ++j) 
            {
                if(error[j] == str[i]) 
                {
                    break;
                }
            }
            if(j == 40) 
                cout<<str[i];
            else 
                cout<<correct[j];
        }
        cout<<endl;
    }
    return 0;
}