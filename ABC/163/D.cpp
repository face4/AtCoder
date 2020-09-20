#include<iostream>
using namespace std;

typedef long long ll;
const ll mod = 1e9+7;

int main(){
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    auto f = [](ll x)->ll{
        return x*(x+1)/2%mod;
    };
    for(ll i = n+1; i >= k; i--){
        ans += f(n+1)-f(n+1-i) - f(i)+1+mod+mod;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}