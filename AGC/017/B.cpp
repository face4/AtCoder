#include<iostream>
using namespace std;
typedef long long ll;
#define inRange(x,a,b) (a <= x && x <= b)

int main(){
    ll n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    bool ok = false;
    for(ll m = 0; m <= n-1; m++){
        ok |= inRange(b-a+m*(c+d), c*(n-1), d*(n-1));
    }
    cout << (ok ? "YES" : "NO") << endl;
    return 0;
}