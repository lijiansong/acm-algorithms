#include<iostream>

using namespace std;

int main(){
    int n;
    int a[10000];
    int count=0;
    int sum=0;
    int id=0;
    while(cin>>n){
        if(n==-1)break;
        count=0;
        sum=0;
        ++id;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]==-1){
                count++;
                sum+=i;
            }
        }
        cout<<"Case "<<id<<": "<<sum-count*(count-1)/2<<endl;
    }    
}