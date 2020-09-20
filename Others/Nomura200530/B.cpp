#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;
    for(char c : s){
        if(c == '?')    cout << 'D';
        else            cout << c;
    }
    cout << endl;
    return 0;
}