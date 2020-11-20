#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;
    ll ans = 0;
    for(ll i = 1; i*i <= n-1; i++){
        if((n-1)%i) continue;
        ans += i>1;
        ans += i!=(n-1)/i;
    }
    for(ll i = 1; i*i <= n; i++){
        if(n%i) continue;
        if(i > 1){
            ll tmp = n;
            while(tmp%i == 0)   tmp /= i;
            ans += tmp%i==1;
        }
        if(i*i == n)    continue;
        ll tmp = n, xi = n/i;
        while(tmp%xi == 0)  tmp /= xi;
        ans += tmp%xi==1;
    }
    cout << ans << endl;
    return 0;
}