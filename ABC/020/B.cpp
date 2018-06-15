#include<iostream>
#include<cmath>
using namespace std;

int main(){
    string a, b;
    cin >> a >> b;
    cout << 2 * stoi(a+b) << endl;
/*
    int power = y.length();
    int a = stoi(x);
    int b = stoi(y);
    while(power-- > 0)  a *= 10;
    a += b;

    cout << 2*a << endl;
*/
    return 0;
}