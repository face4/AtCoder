#include<iostream>
#include<map>
using namespace std;

int main(){
    map<char,int> dict;
    for(char c = '0'; c <= '9'; c++)    dict[c] = c-'0';
    dict['O'] = 0;
    dict['D'] = 0;
    dict['I'] = 1;
    dict['Z'] = 2;
    dict['S'] = 5;
    dict['B'] = 8;
    
    char x;
    while(cin >> x) cout << dict[x];
    cout << endl;

    return 0;
}