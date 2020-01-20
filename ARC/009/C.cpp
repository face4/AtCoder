// 自力AC
#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
const ll mod = 1777777777;

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
    string s;
    ll k;
    cin >> s >> k;
    ll n = 0;
    for(char c : s){
        n = 10*n + c-'0';
        n %= mod;
    }
    ll ans = 1;
    for(int i = 0; i < k; i++){
        (ans *= (n-i+mod)%mod) %= mod;
        (ans *= modpow(i+1, mod-2, mod)) %= mod;
    }
    
    vector<ll> fact(k+1, 1);
    for(int i = 1; i <= k; i++) fact[i] = fact[i-1]*i%mod;
    ModComb mc(k+5);

    ll ans2 = fact[k], sub = 0;
    for(int i = 1; i <= k; i++){
        sub += mc.nCk(k, i)*fact[k-i]%mod*(i%2==0 ? -1 : 1);
        sub += mod;
        sub %= mod;
    }
    ans2 = (ans2 - sub + mod) % mod;

    cout << ans*ans2%mod << endl;
    return 0;
}
