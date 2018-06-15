#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main(){
    double xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;

    xb -= xa;
    yb -= ya;
    xc -= xa;
    yc -= ya;

    cout << fixed << setprecision(3) << fabs(xb*yc-yb*xc)/2.0 << endl;
    
    return 0;
}