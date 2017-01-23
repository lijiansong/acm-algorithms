#include<iostream>
using namespace std;
int main(){
    int n,m;
    while(cin>>n>>m,n!=-1 && m!=-1){
                          int ind=1;
                          while(ind*(ind-1)/2 < m) ++ind;
                          int k=n-ind;
                          for (int i=1;i<=k;++i) cout << i << " ";
                          int ff = m-(ind-1)*(ind-2)/2;
                          cout << ff+k+1 << " ";
                          int ii;
                          for(ii=ind;ii>1;--ii){
                                  if(ff==ii-1) continue;
                                  cout << ii+k << " ";
                                  }
                          cout << ii+k <<endl;;
                          }
    }