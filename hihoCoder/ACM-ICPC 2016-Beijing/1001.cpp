#include<vector>
#include<iostream>
#include <algorithm>
using namespace std;
vector<string> li;

bool isdir(string str, int index) {
    for (int i = index; i < str.length(); ++i) {
        if (str[i] == '/')
            return true;
    }
    return false;
}
bool cmp(const string &a, const string &b) {
    int i;
    for (i = 0; i < a.length() && i < b.length(); ++i) {
        if (a[i] < b[i]) {
            if (!(!isdir(a, i) && isdir(b, i))) {
                return true;
            }
            return false;
        }
        else if (a[i] > b[i]) {
            if (!isdir(a, i) && isdir(b, i)) {
                return true;
            }
            return false;
        }
    }
    if (i == a.length()) {
        if (!(!isdir(a, i) && isdir(b, i))) {
                return true;
            }
            return false;
    }
    if (!isdir(a, i) && isdir(b, i)) {
        return true;
    }
    return false;
}

int main()
{
    string str;
    int num = 0;
    while(cin>>str)
    {
        if(str == "0") {
                cout << "Case " << ++num << ":" << endl;
            sort(li.begin(), li.end(),cmp);
            vector<string>::iterator iter = unique(li.begin(),li.end());
            li.erase(iter,li.end());
//            for (vector<string>::iterator it = li.begin(); it != li.end(); ++it) {
//                    cout << *it << endl;
//            }
            string last = "";
            for (vector<string>::iterator it = li.begin(); it != li.end(); ++it) {
                int j;
                int space = 0;
                for (j = 0; j < last.length() && j < (*it).length(); ++j) {
                    if ((*it)[j] == '/') {
                       ++space;
                    }
                    if (last[j] != (*it)[j])
                        break;
                }

                while (j > 0 && (*it)[j - 1] != '/') {
                    --j;
                }

                for (int k = 0; k < space; ++k)
                    cout << "    ";
                for (; j < (*it).length(); ++j) {
                    if ((*it)[j] == '/') {
                        ++space;
                        cout << endl;
                        for (int k = 0; k < space; ++k)
                            cout << "    ";
                    }
                    else
                        cout << (*it)[j];
                }
                cout << endl;
                last = *it;
            }
            li.clear();
        } else {
            li.push_back(str);
        }
    }
    return 0;
}

