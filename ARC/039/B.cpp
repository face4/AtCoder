#include<iostream>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

ll modpow(ll a, ll b, ll p = 1e9+7){
    if(b == 0)  return 1;

    if(b % 2 == 0){
        ll d = modpow(a, b/2, p);
        return (d*d) % p;
    }else{
        return (a%mod * modpow(a, b-1, p)) % p;
    }
}

ll nCm(ll n, ll m, ll p = 1e9+7){
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
    int n, k;
    cin >> n >> k;

    if(k < n){
        cout << nCm(n+k-1, n-1) << endl;
        return 0;
    }

    cout << nCm(n, k%n) << endl;

    return 0;
}