#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
#define inRange(x,a,b) (a <= x && x <= b)

const double pi = 2*acos(0.0);

int main(){
    double a, b, c;
    cin >> a >> b >> c;

    auto f = [=](double t) -> double{
        return a*t + b*sin(c*t*pi);
    };

    // 中間値の定理
    double l = 0.0, r = 100.0;
    while(r-l > 1e-11){
        double mid = (l+r)/2;
        if(inRange(100.0, f(mid), f(r)))  l = mid;
        else r = mid;
    }

    cout << fixed << setprecision(14) << l << endl;

    return 0;
}
