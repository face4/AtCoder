#include<iostream>
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

struct ModComb{
    vector<ll> po, inv;
    ll N;

    ModComb(ll n) : N(n), po(n), inv(n) {
        po[0] = 1;
        for(int i = 1; i < N; i++)  po[i] = (po[i-1] * i) % mod;
        inv[N-1] = modpow(po[N-1], mod-2, mod);
        for(int i = N-2; i >= 0; i--)   inv[i] = (inv[i+1] * (i+1)) % mod;
    }
    
    ll nCk(ll n, ll k){
        if(k == 0)  return 1;
        if(n < k)   return 0;
        return (((po[n]*inv[n-k])%mod)*inv[k])%mod;
    }

    ll nPk(ll n, ll k){
        if(k == 0)  return 1;
        if(n < k)   return 0;
        return (po[n]*inv[n-k])%mod;
    }

    ll nHk(ll n, ll k){
        if(n == 0 && k == 0)    return 1;
        return nCk(n+k-1, k-1);
    }
};

int main(){
    ll n, m;
    cin >> n >> m;
    ModComb mc(m+1);
    ll ans = mc.nPk(m, n);
    for(int i = 1; i <= n; i++){
        ans += mc.nCk(n, i) * mc.nPk(m-i, n-i) % mod * (i%2==1 ? -1 : 1) + mod;
        ans %= mod;
    }
    ans *= mc.nPk(m, n);
    ans %= mod;
    cout << ans << endl;
    return 0;
}