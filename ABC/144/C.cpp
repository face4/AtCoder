#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    ll x;
    cin >> x;
    ll ans = x;
    for(ll i = 1; i*i <= x; i++){
        if(x%i) continue;
        ans = min(ans, i-1 + x/i-1);
    }
    cout << ans << endl;
    return 0;
}