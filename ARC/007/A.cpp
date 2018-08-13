#include<iostream>
using namespace std;

int main(){
    char x;
    string s;
    cin >> x >> s;

    for(int i = 0; i < s.length(); i++){
        if(s[i] == x)   continue;
        cout << s[i];
    }

    cout << endl;

    return 0;
}