#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

const double PI = acos(0.0)*2;

int main(){
    double r;
    cin >> r;
    cout << fixed << setprecision(12) << r*2*PI << endl;
    return 0;
}