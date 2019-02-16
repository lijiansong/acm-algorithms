/*
    Name: 
    Copyright: 
    Author: 
    Date: 14/01/16 13:34
    Description: woj1295
    ¿®∫≈∆•≈‰ 
*/
#include<iostream>
#include<stdio.h>
#include<stack>
using namespace std;
stack<char> s;
int j=0;
char match(char ch)
{
    switch(ch)
    {
        case '{':
            return '}';
        case '[':
            return ']';
        case '(':
            return ')';
    }
}
bool judge(char str[])
{
    while(s.size())
        s.pop();
    for(j=0;str[j]!='\0';++j)
    {
        if(str[j]=='+'||str[j]=='-'||str[j]=='*'||str[j]=='/'||(str[j]>='0'&&str[j]<='9')||(str[j]>='a'&&str[j]<='z')||(str[j]>='A'&&str[j]<='Z'))
            continue;
        else if(str[j]=='{'||str[j]=='('||str[j]=='[')
            s.push(str[j]);
        else
        {
            if(s.empty())
                return false;
            else
            {
                if(match(s.top())==str[j])
                    s.pop();
                else
                    return false;
            }
            
        }
    }
    if(s.size())
        return false;
    else
        return true;        
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    while(cin>>n)
    {
        char str[101];
        int i=0;
        for(i=0;i<n;++i)
        {
            cin>>str;
            if(judge(str))
                cout<<"Case "<<i+1<<": Legal"<<endl;
            else
                cout<<"Case "<<i+1<<": Illegal"<<endl;
        }
    }
    return 0;
}