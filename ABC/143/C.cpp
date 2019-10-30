#include<iostream>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n >> s;
    int ans = 1;
    for(int i = 1; i < n; i++)  ans += s[i]!=s[i-1];
    cout << ans << endl;
    return 0;
}