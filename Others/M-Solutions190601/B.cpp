#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;
    int cnt = 0;
    for(char c : s) cnt += (c=='o');
    cout << (cnt+(15-s.length()) >= 8 ? "YES" : "NO") << endl;
    return 0;
}