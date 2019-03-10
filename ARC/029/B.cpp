#include<iostream>
#include<cmath>
using namespace std;
const double PI = acos(0)*2;

int main(){
    int a, b, n;
    cin >> a >> b >> n;
    if(a > b)   swap(a, b);

    auto f = [=](int c, int d)-> bool{
        if((a <= c && b <= d) || (a <= d && b <= c))    return true;
        if(c > d)   swap(c, d);
        double l = 0, r = PI/2;
        for(int i = 0; i < 100; i++){
            double mid = (l+r)/2;
            double height = a*cos(mid)+b*sin(mid);
            if(a*cos(l)+b*sin(l) <= c && b*cos(l)+a*sin(l) <= d)    return true;
            if(height <= c) l = mid;
            else            r = mid;
        }
        return a*cos(l)+b*sin(l) <= c && b*cos(l)+a*sin(l) <= d;
    };

    int c, d;
    for(int i = 0; i < n; i++){
        cin >> c >> d;
        cout << (f(c,d) ? "YES" : "NO" ) << endl;
    }
    return 0;
}