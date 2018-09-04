#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int l, x, y, s, d;
    cin >> l >> x >> y >> s >> d;

    if(s > d)   d += l;
    double ans = double(d-s) / (x+y);
    if(y > x)   ans = min(ans, double(l+s-d) / (y-x));
    
    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}