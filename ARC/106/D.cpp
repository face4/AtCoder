// editorial
#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

typedef long long ll;
const ll mod = 998244353;

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
    vector<ll> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i];
    vector<ll> fact(k+1, 1);
    for(int i = 1; i <= k; i++) fact[i] = fact[i-1]*i%mod;
    vector<ll> invf(k+1, 1);
    for(int i = 1; i <= k; i++) invf[i] = modpow(fact[i], mod-2, mod);
    vector<ll> sum(k+1, 0);
    sum[0] = n;
    vector<ll> powers(n, 1);
    for(int i = 1; i <= k; i++){
        for(int j = 0; j < n; j++){
            powers[j] = powers[j]*v[j]%mod;
            (sum[i] += powers[j]*invf[i]%mod) %= mod;
        }
    }
    const ll invtwo = modpow(2, mod-2, mod);
    vector<ll> fpowers(n, 1);
    for(int i = 1; i <= k; i++){
        ll tmp = 0, sub = 0;
        for(int j = 0; j <= i; j++){
            (tmp += sum[j]*sum[i-j]%mod) %= mod;
        }
        (tmp *= fact[i]) %= mod;
        for(int j = 0; j < n; j++){
            fpowers[j] = fpowers[j]*2*v[j]%mod;
            (sub += fpowers[j]) %= mod;
        }
        cout << (tmp-sub+mod)*invtwo%mod << endl;
    }
    return 0;
}