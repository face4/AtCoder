#include<iostream>
using namespace std;

int main(){
    char c;
    cin >> c;
    if(c == 'A')    cout << 'T' << endl;
    if(c == 'T')    cout << 'A' << endl;
    if(c == 'C')    cout << 'G' << endl;
    if(c == 'G')    cout << 'C' << endl;
    return 0;
}