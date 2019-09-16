#include<iostream>
using namespace std;

int main(){
    int n, k;
    string s;
    cin >> n >> k >> s;

    int ans = 0, diff = 0;
    for(int i = 1; i < n; i++){
        diff += s[i] != s[i-1];
        if(s[i] == s[i-1])  ans++;
    }
    while(k-- > 0 && diff > 0){
        ans += min(2, diff);
        diff-=2;
    }
    cout << ans << endl;
    return 0;
}