#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;

    int ans = 0;
    bool zero = false;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '+'){
            if(!zero)   ans++;
            zero = false;
        }else if(s[i] == '0'){
            zero = true;
        }
    }

    if(!zero)   ans++;
    
    cout << ans << endl;
    return 0;
}