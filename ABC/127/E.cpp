#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

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

// the number of ways to choose x_i and x_j so that their difference be d
// is (n-d)*m*m.
// the number of ways to choose n*m-2 cells other than the fixed two 
// is  {n*m-2}C{k-2}.

int main(){
    ll n, m, k;
    cin >> n >> m >> k;

    ModComb mc(n*m+2);
    ll tmp = mc.nCk(n*m-2, k-2);

    ll ans = 0;
    
    // x-axis
    for(ll d = 1; d < n; d++){
        ans += d*(n-d)*m%mod*m%mod*tmp%mod;
        ans %= mod;
    }

    // y-axis
    for(ll d = 1; d < m; d++){
        ans += d*(m-d)*n%mod*n%mod*tmp%mod;
        ans %= mod;
    }

    cout << ans << endl;

    return 0;
}