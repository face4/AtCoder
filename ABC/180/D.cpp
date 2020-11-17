#include<iostream>
using namespace std;

typedef long long ll;

int main(){
    ll x, y, a, b;
    cin >> x >> y >> a >> b;
    ll ans = 0;
    for(ll i = 0;;i++){
        ans = max(i+(y-1-x)/b, ans);
        if(a >= (y+x-1)/x)  break;
        x *= a;
    }
    cout << ans << endl;
    return 0;
}