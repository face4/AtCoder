#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;
    bool b = true;
    for(int i = 0; i < s.length(); i++){
        if(i%2 == 0)    b &= (s[i] != 'L');
        else            b &= (s[i] != 'R');
    }
    cout << (b ? "Yes" : "No") << endl;
    return 0;
}