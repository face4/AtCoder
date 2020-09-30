#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;
    int ans = 0, tmp = 0;
    for(char c : s){
        if(c == 'R')    tmp++;
        else            tmp = 0;
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}