#include<iostream>
#include<map>
using namespace std;

typedef long long ll;
const ll mod = 1000000007;

ll modpow(ll a, ll b, ll p = 1e9+7){
    if(b == 0)  return 1;

    if(b % 2 == 0){
        ll d = modpow(a, b/2, p);
        return (d*d) % p;
    }else{
        return (a%p * modpow(a, b-1, p)) % p;
    }
}

ll nCm(ll n, ll m, ll p = mod){
    ll ret = 1;
    
    // nCm == nC(n-m)
    if(m > n/2) m = n-m;

    for(ll i = 1; i <= m; i++){
        ret *= n-(i-1);
        ret %= p;
        ret *= modpow(i, p-2, p);
        ret %= p;
    }
    
    return ret;
}

int main(){
    int n, m;
    cin >> n >> m;

    map<int,int> fact;
    for(int i = 2; i*i <= m; i++){
        while(m%i == 0){
            fact[i]++;
            m /= i;
        }
    }
    if(m != 1)  fact[m]++;

    ll ans = 1;
    for(auto p : fact){
        ans *= nCm(n+p.second-1, p.second);
        ans %= mod;
    }

    cout << ans << endl;
    return 0;
}
