#include<iostream>
#include<map>
using namespace std;

int main(){
    string s, t;
    cin >> s >> t;

    int n = s.length();

    bool doubling = false;
    map<char,char> ma, mb;

    for(int i = 0; i < n; i++){
        if(ma.count(s[i]) && ma[s[i]] != t[i]){
            doubling = true;
            break;
        }else{
            ma[s[i]] = t[i];
        }
        if(mb.count(t[i]) && mb[t[i]] != s[i]){
            doubling = true;
            break;
        }else{
            mb[t[i]] = s[i];
        }
    }

    if(doubling)    cout << "No" << endl;
    else            cout << "Yes" << endl;

    return 0;
}
