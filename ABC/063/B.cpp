#include<iostream>
using namespace std;

int main(){
    string s;
    bool appear[26] = {};

    cin >> s;
    for(int i = 0; i < s.length(); i++){
        int index = s[i]-'a';
        if(appear[index]){
            cout << "no" << endl;
            return 0;
        }
        appear[index] = true;
    }

    cout << "yes" << endl;
    return 0;
}