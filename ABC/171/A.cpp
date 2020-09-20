#include<iostream>
using namespace std;

int main(){
    char c;
    cin >> c;
    if('a' <= c && c <= 'z')    c = 'a';
    else                        c = 'A';
    cout << c << endl;
    return 0;
}