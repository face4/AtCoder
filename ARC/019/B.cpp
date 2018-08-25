#include<iostream>
#include<vector>
using namespace std;

bool isPalindrome(string s){
    int n = s.length();
    for(int i = 0; i < n/2; i++){
        if(s[i] != s[n-1-i])    return false;
    }
    return true;
}

vector<int> diff(string s){
    int n = s.length();
    vector<int> ret;
    for(int i = 0; i < n/2; i++){
        if(s[i] != s[n-1-i])    ret.push_back(i);
    }
    return ret;
}

int main(){
    string a;
    cin >> a;

    if(isPalindrome(a)){
        if(a.length() % 2 == 0) cout << 25 * a.length() << endl;
        else                    cout << 25 * (a.length()-1) << endl;
        return 0;
    }

    vector<int> difference = diff(a);
    if(difference.size() > 1){
        cout << 25 * a.length() << endl;
    }else{
        cout << 24 * 2 + 25 * (a.length()-2) << endl;
    }

    return 0;
}