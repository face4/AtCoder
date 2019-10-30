#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main(){
    const double PI = 2.0 * acos(0);
    double a, b, x;
    cin >> a >> b >> x;
    double piv = atan2(b,a)/PI*180.0;
    double l = 0.0, r = 91;
    for(int i = 0; i < 200; i++){
        double mid = (l+r)/2;
        double afford;
        if(mid < piv){
            afford = a*a*b-a*a/2*a*tan(mid/180*PI);
        }else{
            afford = b*a/2*b*tan((90-mid)/180*PI);
        }
        if(afford >= x) l = mid;
        else            r = mid;
    }
    cout << fixed << setprecision(12) << l << endl;
    return 0;
}