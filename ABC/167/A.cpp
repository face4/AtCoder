#include<iostream>
using namespace std;

int main(){
    string s, t;
    cin >> s >> t;
    cout << (s==t.substr(0,s.length()) ? "Yes" : "No") << endl;
    return 0;
}