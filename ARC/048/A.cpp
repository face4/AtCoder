#include<iostream>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;

    if(a < 0 && 0 < b)  cout << b-a-1 << endl;
    else                cout << b-a << endl;

    return 0;
}