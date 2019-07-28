#include<iostream>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    if(abs(a-b)%2)  cout << "IMPOSSIBLE" << endl;
    else            cout << (a+b)/2 << endl;
    return 0;
}