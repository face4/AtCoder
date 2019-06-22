#include<iostream>
#include<iomanip>
using namespace std;
typedef long long ll;

// ??
int main(){
    ll w, h, x, y;
    cin >> w >> h >> x >> y;
    double s = w*h/2.0;
    cout << fixed << setprecision(12) << s << " ";
    int cnt = 0;
    cnt +=  (w%2 == 0 && w/2 == x);
    cnt +=  (h%2 == 0 && h/2 == y);
    if(cnt <= 1 || x == 0 || x == w || y == 0 || y == h)    cout << 0 << endl;
    else                                        cout << 1 << endl;
    return 0;
}