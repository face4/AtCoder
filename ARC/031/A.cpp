#include<iostream>
using namespace std;

bool isPalindrome(string s){
    int n = s.length();
    for(int i = 0; i < n/2; i++){
        if(s[i] != s[n-1-i])    return false;
    }
    return true;
}

int main(){
    string s;
    cin >> s;
    if(isPalindrome(s)) cout << "YES" << endl;
    else                cout << "NO" << endl;
    return 0;
}