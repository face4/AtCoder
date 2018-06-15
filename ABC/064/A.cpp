#include<iostream>
using namespace std;

int main(){
    int r, g, b;
    cin >> r >> g >> b;
    cout << ( (100*r+10*g+b)%4 ? "NO" : "YES" )<< endl;
    return 0;
}