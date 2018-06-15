#include<iostream>
using namespace std;

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a += b;
    c += d;
    if(a < c)       cout << "Right" << endl;
    else if(a > c)  cout << "Left" << endl;
    else            cout << "Balanced" << endl;
    return 0;
}