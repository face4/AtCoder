#include<iostream>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

ll po[200005] = {};
ll inv[200005] = {};

ll modpow(ll a, ll b, ll p = 1e9+7){
    if(b == 0)  return 1;

    if(b % 2 == 0){
        ll d = modpow(a, b/2, p);
        return (d*d) % p;
    }else{
        return (a%p * modpow(a, b-1, p)) % p;
    }
}

ll nCm(ll n, ll m, ll p = 1e9+7){
    ll ret = 1;
    ret *= po[n];
    ret %= p;
    ret *= inv[n-m];
    ret %= p;
    ret *= inv[m];
    ret %= p;
    return ret;
}

int main(){
    po[0] = 1;
    for(int i = 1; i < 200005; i++){
        po[i] = po[i-1] * i;
        po[i] %= mod;
    }
    inv[0] = 1;
    for(int i = 1; i < 200005; i++){
        inv[i] = modpow(po[i], mod-2, mod);
    }

    int h, w, a, b;
    cin >> h >> w >> a >> b;

    ll ans = 0;
    int hei = h-1-a;
    
    for(int wid = b; wid < w; wid++){
        ans += nCm(wid+hei, wid) * nCm(a-1+w-1-wid, a-1);
        ans %= mod;
    }

    cout << ans << endl;

    return 0;
}