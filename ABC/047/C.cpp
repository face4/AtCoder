#include<iostream>
using namespace std;

int main(){
    int ans = 0;
    string s;
    cin >> s;

    char now = s[0];

    for(int i = 1; i < s.size(); i++){
        if(now != s[i]){
            ans++;
            now = s[i];
        }
    }

    cout << ans << endl;
    return 0;
}