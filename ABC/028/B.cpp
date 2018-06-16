#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;
    int cnt[6] = {};

    for(int i = 0; i < s.length(); i++){
        cnt[s[i]-'A']++;
    }

    for(int i = 0; i < 6; i++){
        if(i)   cout << " ";
        cout << cnt[i];
    }
    cout << endl;
    
    return 0;
}