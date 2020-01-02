#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.length();
    int ret = 0;
    for(int i = 0; i < n/2; i++){
        ret += s[i] != s[n-1-i];
    }
    cout << ret << endl;
    return 0;
}