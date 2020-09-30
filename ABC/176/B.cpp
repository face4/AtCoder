#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;
    int res = 0;
    for(char c : s) res += c-'0';
    res %= 9;
    cout << (res==0 ? "Yes" : "No") << endl;
    return 0;
}