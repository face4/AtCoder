#include<iostream>
using namespace std;

int main(){
    char C, c;
    cin >> C >> c;
    if(C-'A' == c-'a')  cout << "Yes" << endl;
    else                cout << "No" << endl;
    return 0;
}