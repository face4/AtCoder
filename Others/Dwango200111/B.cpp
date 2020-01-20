#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const int mod = 1000000007;

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
    int n;
    cin >> n;
    vector<ll> x(n);
    for(int i = 0; i < n; i++)  cin >> x[i];
    
    vector<ll> v(n+5);
    v[1] = 1;
    ll fact = 1;
    for(int i = 1; i+1 < n+2; i++){
        v[i+1] = ((i+1)*v[i]+fact)%mod;
        (fact *= (i+1)) %= mod;
    }
    ModComb mc(n+5);
    
    vector<ll> f(n+2);
    f[0] = 1;
    for(int i = 1; i <= n+1; i++)   f[i] = f[i-1]*i%mod;

    ll ans = 0;
    for(int i = 1; i < n; i++){
        ans += (x[i]-x[i-1])*v[i]%mod*mc.nCk(n-1, n-1-i)%mod*f[n-1-i]%mod;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}