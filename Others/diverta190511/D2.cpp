#include<iostream>
using namespace std;

typedef long long ll;

int main(){
    ll n;
    cin >> n;
    ll ans = 0;
    for(ll i = 1; i*i <= n; i++){
        if(n%i) continue;
        ll a = i, b = n/i;
        if(b-1 > a) ans += b-1;
        if(a-1 > b) ans += a-1;
    }
    cout << ans << endl;
    return 0;
}