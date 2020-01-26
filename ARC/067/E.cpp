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

// n人からm人のグループk個を作る通り数(グループは区別しない)は
// n! / k! / (m!)^k

int main(){
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    ModComb mc(2*n);
    // 総人数、1グループの人数
    vector<vector<ll>> dp(n+1, vector<ll>(n+1, 0));
    
    vector<ll> memo(n+1);
    for(int j = c; j <= d; j++) memo[j] = modpow(mc.po[j], mod-2);

    dp[0][a-1] = 1;
    for(int mem = a; mem <= b; mem++){
        for(int i = 0; i <= n; i++){
            dp[i][mem] = dp[i][mem-1];
            ll f = modpow(mc.inv[mem], c);
            for(int j = c; j <= min(d, i/mem); j++){
                (dp[i][mem] += dp[i-mem*j][mem-1]*mc.nPk(n-(i-mem*j), mem*j)%mod*memo[j]%mod*f%mod) %= mod;
                (f *= mc.inv[mem]) %= mod;
            }
        }
    }
    cout << dp[n][b] << endl;
    return 0;
}