/*
    Name: 
    Copyright: 
    Author: 
    Date: 27/12/15 06:45
    Description: woj1165
*/
#include<iostream>
#include<stdio.h>
using namespace std;
bool IsPrime(int n)
{
    int i;
    for (i = 2; i*i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
int SumOfDigits(int n)
{
    int sum = 0;
    while (n != 0)
    {
        sum += n%10;
        n /= 10;
    }
    return sum;
}

int SumOfPrimeFactors(int n)
{
    int sum = 0;
    int i = 2;
    while (true)
    {
        if (n % i == 0)
        {
            sum += SumOfDigits(i);
            if (IsPrime(n /= i))
            {
                break;
            }
        }
        else
        {
            i++;
        }
    }
    return sum += SumOfDigits(n);
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    while (cin>>n&&n!=0)
    {
        if(!IsPrime(n))//素数肯定不是史密斯数 
        {
            if(SumOfDigits(n) == SumOfPrimeFactors(n))
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
        else
            cout<<"No"<<endl;
    }
    return 0;
}