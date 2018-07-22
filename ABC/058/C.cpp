#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int appear[26];
    for(int i = 0; i < 26; i++) appear[i] = 51;

    string s;
    for(int i = 0; i < n; i++){
        cin >> s;
        int tmp[26] = {};
        for(int j = 0; j < s.length(); j++){
            tmp[s[j] - 'a']++;
        }
        for(int j = 0; j < 26; j++){
            appear[j] = min(appear[j], tmp[j]);
        }
    }

    for(int i = 0; i < 26; i++){
        for(int j = 0; j < appear[i]; j++){
            cout << (char)('a' + i);
        }
    }
    cout << endl;

    return 0;
}