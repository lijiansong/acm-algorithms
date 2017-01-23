#include<iostream>
using namespace std;
int main(){
    int c;
    cin >> c;
    while(c--){
        int n;
        cin >> n;
        if (n%7 == 0 || n%7 == 1) cout << "Dzs" << endl;
        else cout << "Sproblvem" << endl;
    }
    return 0;
}