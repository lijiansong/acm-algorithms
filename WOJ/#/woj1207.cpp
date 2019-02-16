#include<iostream>
#include<string>
using namespace std;
string minhw(string s){
      string ts1 = "",ts2 = "";
      int len,index;
      len = s.length();
      if (len%2 == 0){
                index = len/2;
                for (int i=0; i<index; i++){ts1 += s[index-1-i]; ts2 += s[index+i];}
                if (ts1 > ts2){
                        for (int i=0; i<index; i++) s[index+i] = ts1[i];
                        }
                else if (ts1 == ts2){}
                else{
                      --index;
                      while(s[index] == '9' && index >=0){s[index] = '0';--index;}
                      if (index >=0){
                                s[index] += 1;
                                for (int i=len/2; i<len; i++) s[i] = s[len-1-i];
                                }
                      else {
                          for (int i=0; i<len-1; i++) s[i] = '0';
                          s[len-1] = '1'; 
                          s.insert(0,1,'1');
                          }
                      }

                }
      else{
            index = (len-1)/2;
            for (int i=0; i<index; i++) {ts1 += s[index-1-i]; ts2 += s[index+1+i];}
            if (ts1 > ts2){
              for (int i=0; i<index; i++) s[index+1+i] = ts1[i];
              }
            else if (ts1 == ts2){}
            else{
                  while(s[index] == '9' && index >= 0){s[index] = '0';--index;}
                  if (index >=0){
                    s[index] += 1;
                    for (int i=(len-1)/2; i<len; i++) s[i] = s[len-i-1];
                    }
                  else{
                      for(int i=0; i<len-1; i++) s[i] = '0';
                      s[len-1] = '1';
                      s.insert(0,1,'1');
                      }
                  }
            }
      return s;
      }

int main(){
    string s;
    while(cin>>s){cout << minhw(s) << endl;}
    return 0;
    }