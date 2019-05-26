#include<iostream>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n >> s;
    int cnt = 0;
    for(char c : s) if(c == 'R')    cnt++;
    if(cnt > n-cnt) cout << "Yes" << endl;
    else            cout << "No" << endl;
    return 0;
}