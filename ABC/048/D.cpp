#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;
    if((s.length()%2)+(s[0]==s[s.length()-1]) == 1)  cout << "First" << endl;
    else            cout << "Second" << endl;
    return 0;
}