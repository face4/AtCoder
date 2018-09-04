#include<iostream>
#include<cctype>
using namespace std;

int main(){
    string s;
    cin >> s;

    int ans;
    for(int i = 0;; i++){
        if(isdigit(s[i])){
            if(isdigit(s[i+1])){
                ans = (s[i] - '0')*10 + s[i+1] - '0';
            }else{
                ans = s[i] - '0';
            }
            break;
        }
    }

    cout << ans << endl;

    return 0;
}