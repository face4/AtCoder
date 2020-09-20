#include<iostream>
using namespace std;

bool isb(string &s){
    int n = s.length();
    for(int i = 0; i < n; i++)  if(s[i] != s[n-1-i])    return false;
    return true;
}

int main(){
    string s;
    cin >> s;
    int n = s.length();
    string t = s.substr(0,(n-1)/2);
    string u = s.substr((n+3)/2-1);
    cout << (isb(s)&&isb(t)&&isb(u) ? "Yes" : "No") << endl;
    return 0;
}