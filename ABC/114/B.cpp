#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;

    int ans = 1000;
    for(int i = 0; i < s.length()-2; i++){
        int tmp = 100*(s[i]-'0') + 10*(s[i+1]-'0') + s[i+2]-'0';
        ans = min(ans, abs(tmp-753));
    }

    cout << ans << endl;
    
    return 0;
}