#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;
    if(s.back() == 's') s += 'e';
    s += 's';
    cout << s << endl;
    return 0;
}