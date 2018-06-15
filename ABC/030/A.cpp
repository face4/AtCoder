#include<iostream>
using namespace std;

int main(){
    double a, b, c, d;
    cin >> a >> b >> c >> d;

    double taka = b / a;
    double aoki = d / c;

    if(taka > aoki) cout << "TAKAHASHI" << endl;
    if(taka < aoki) cout << "AOKI" << endl;
    if(taka == aoki)    cout << "DRAW" << endl;

    return 0;
}