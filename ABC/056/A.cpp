#include<iostream>
using namespace std;

int main(){
    char a, b;
    cin >> a >> b;
    cout << (a==b ? 'H' : 'D') << endl;
    /*
    if(a == 'H' && b == 'D')    cout << "D" << endl;
    if(a == 'H' && b == 'H')    cout << "H" << endl;
    if(a == 'D' && b == 'D')    cout << "H" << endl;
    if(a == 'D' && b == 'H')    cout << "D" << endl;
    */
    return 0;
}