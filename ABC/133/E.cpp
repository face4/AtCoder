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

int n, k;
vector<int> v[100000];
vector<ll> fact(100001, 1);
vector<bool> b(100000, 0);
ModComb mc(101010);
ll ans = 1;

void dfs(int pos){
    int child = 0, nc = 0;
    for(int next : v[pos]){
        if(b[next]){
            nc++;
        }else {
            child++;
        }
    }
    // cout << pos << endl;
    // cout << mc.nCk(k-1-nc, child) << endl;
    // cout << fact[child] << endl;
    ans = ans * mc.nCk(k-1-nc, child) % mod * fact[child] % mod;
    for(int next : v[pos]){
        if(!b[next]){
            b[next] = true;
            dfs(next);
        }
    }
}

int main(){
    for(int i = 1; i < 100001; i++){
        fact[i] = fact[i-1] * i % mod;
    }

    cin >> n >> k;
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    b[0] = true;
    ans = k;
    dfs(0);
    cout << ans << endl;
    return 0;
}