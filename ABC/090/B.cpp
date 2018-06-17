#include<iostream>
using namespace std;

bool isPalindrome(int x){
    string s = to_string(x);
    int len = s.length();
    for(int i = 0; i < len/2; i++){
        if(s[i] != s[len-i-1])    return false;
    }
    return true;
}

int main(){
    int a, b;
    cin >> a >> b;

    int ans = 0;
    for(int i = a; i <= b; i++){
        if(isPalindrome(i)) ans++;
    }

    cout << ans << endl;
    return 0;
}