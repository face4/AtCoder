#include<iostream>
using namespace std;

int main(){
    string s, t;
    cin >> s >> t;
    int ans = 0;
    for(int i = 0; i < s.length(); i++){
        ans += s[i] != t[i];
    }
    cout << ans << endl;
    return 0;
}