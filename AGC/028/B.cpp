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

int main(){
    int n;
    cin >> n;
    
    ll inv[n+1];
    for(int i = 1; i <= n; i++) inv[i] = modpow(i, mod-2, mod);

    // frac[i] := \sum_i=1^n{1/i}
    ll frac[n+1];
    frac[0] = 0;
    for(int i = 1; i <= n; i++){
        frac[i] = (frac[i-1] + inv[i])%mod;
    }

    // fact := n!
    ll fact = 1;
    for(int i = 2; i <= n; i++) fact = (fact*i)%mod;
    
    ll ans = 0;
    ll a;

    for(int i = 0; i < n; i++){
        cin >> a;
        ans += (a * (frac[i+1]+frac[n-i]-1))%mod;
        ans %= mod;
    }

    cout << (ans*fact)%mod << endl;

    return 0;
}