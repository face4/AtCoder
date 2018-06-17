#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;

    bool appear[26] = {};
    for(int i = 0; i < s.length(); i++){
        appear[s[i]-'a'] = true;
    }

    for(int i = 0; i < 26; i++){
        if(!appear[i]){
            cout << (char)(i+'a') << endl;
            return 0;
        }
    }

    cout << "None" << endl;
    return 0;
}