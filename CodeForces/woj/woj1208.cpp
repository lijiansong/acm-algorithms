#include <iostream>  
#include <stdio.h>
#include <queue>  
#include <algorithm>
using namespace std;  
int main()  
{
    //freopen("in.txt","r",stdin);
    int n;  
    int num1[50000];  
    int num2[50000];  
    priority_queue<int,deque<int>,less<int> > big;
    while(scanf("%d",&n)!=EOF)
    { 
        for(int i=0;i<n;i++)  
            scanf("%d",&num1[i]);  
        sort(num1,num1+n);
        for(int j=0;j<n;j++)  
        {  
            scanf("%d",&num2[j]);  
            big.push(num1[0]+num2[j]);  
        }  
        sort(num2,num2+n);  
        for(int k=1;k<n;k++) 
            for(int l=0;l<n;l++)  
            {  
                if(num1[k]+num2[l]>big.top())  
                    break;  
                    big.pop();  
                    big.push(num1[k]+num2[l]);  
            }  
        for(int k=0;k<n;k++)  
        {  
            num1[n-k-1]=big.top();  
            big.pop();  
        }
        printf("%d",num1[0]);  
        for(int i=1;i<n;i++)  
            printf(" %d",num1[i]);
        //puts(""); 
    }
    return 0;
}