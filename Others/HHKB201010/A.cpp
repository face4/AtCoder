#include<iostream>
using namespace std;

int main(){
    char s, t;
    cin >> s >> t;
    if(s == 'Y')    t = (char)('A'+(t-'a'));
    cout << t << endl;
    return 0;
}