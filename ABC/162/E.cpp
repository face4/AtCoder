#include<iostream>
#include<numeric>
#include<vector>
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

int main(){
    int n, k;
    cin >> n >> k;
    vector<ll> sub(k+1, 0);
    ll ans = 0;
    for(int g = k; g >= 1; g--){
        ll num = k/g;
        ll tmp = modpow(num, n, mod);
        ll add = (tmp-sub[g]+mod)%mod;
        ans += add*g;
        ans %= mod;
        for(int j = 1; j*j <= g; j++){
            if(g%j) continue;
            sub[j] = (sub[j]+add)%mod;
            if(j != g/j)    sub[g/j] = (sub[g/j]+add)%mod;
        }
    }
    cout << ans << endl;
    return 0;
}