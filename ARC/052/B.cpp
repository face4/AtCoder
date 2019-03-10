#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

const double PI = (acos(0)*2);

int main(){
    int n, q;
    cin >> n >> q;
    double x[n], r[n], h[n];
    for(int i = 0; i < n; i++)  cin >> x[i] >> r[i] >> h[i];
    auto f = [&](int i, double t)->double{
        return PI*(r[i]/h[i])*(r[i]/h[i])*(t*t*t/3-(x[i]+h[i])*t*t+(x[i]+h[i])*(x[i]+h[i])*t);
    };
    double a, b;
    while(q-- > 0){
        cin >> a >> b;
        double ans = 0;
        for(int i = 0; i < n; i++){
            int s = max(a, x[i]), t = min(b, x[i]+h[i]);
            if(s >= t)  continue;
            ans += f(i,t)-f(i,s);
        }
        cout << fixed << setprecision(12) << ans << endl;
    }
    return 0;
}