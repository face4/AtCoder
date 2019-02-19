#include<iostream>
using namespace std;

typedef long long ll;

int main(){
    ll n, h, a, b, c, d, e;
    cin >> n >> h >> a >> b >> c >> d >> e;
    ll ans = 1ll<<60;
    if(h-e*n > 0){
        ans = 0;
    }
    ll target = e*n-h+1;
    for(ll i = 0; i <= n; i++){
        ans = min(ans, i*c + (target-(d+e)*i>0 ? (target-(d+e)*i+b+e-1)/(b+e)*a : 0));
    }
    cout << ans << endl;
    return 0;
}