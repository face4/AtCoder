#include<iostream>
using namespace std;

typedef long long ll;
const ll mod = 1e9+7;

ll modpow(ll a, ll b, ll p = 1e9+7){
    if(b == 0)  return 1;

    if(b % 2 == 0){
        ll d = modpow(a, b/2, p);
        return (d*d) % p;
    }else{
        return (a%p * modpow(a, b-1, p)) % p;
    }
}

ll ncm(ll n, ll a){
    ll ret = 1;
    for(int i = 0; i < a; i++){
        (ret *= n-i) %= mod;
        (ret *= modpow(i+1, mod-2, mod)) %= mod;
    }
    return ret;
}

int main(){
    ll n, a, b;
    cin >> n >> a >> b;
    ll ans = modpow(2, n, mod);
    ans += (mod-ncm(n, a));
    ans %= mod;
    ans += (mod-ncm(n, b));
    ans %= mod;
    cout << (ans-1+mod)%mod << endl;
    return 0;
}