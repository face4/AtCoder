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
    int r, c, x, y, d, l;
    cin >> r >> c >> x >> y >> d >> l;

    ll p[1000], inv[1000];
    p[0] = 1;   inv[0] = 1;
    for(int i = 1; i < 1000; i++){
        p[i] = (p[i-1] * i)%mod;
        inv[i] = (inv[i-1]*modpow(i, mod-2, mod))%mod;
    }

    auto comb = [=](ll n, ll m) -> ll{
        return (((p[n]*inv[m])%mod)*inv[n-m])%mod;
    };

    ll ans = (comb(x*y, d)*comb(x*y-d, l))%mod;

    bool a = (x*(y-1) >= d+l);
    bool b = ((x-1)*y >= d+l);

    // 部分点に該当する部分、なんか間違っている
    if(a)
        ans = (ans + mod - (2*comb(x*(y-1), d)*comb(x*(y-1)-d, l))%mod )%mod;
    if(b)
        ans = (ans + mod - (2*comb(y*(x-1), d)*comb(y*(x-1)-d, l))%mod )%mod;
    if((x-1)*(y-1) >= d+l)
        ans = (ans + 3*(comb((x-1)*(y-1), d)*comb((x-1)*(y-1)-d, l))%mod )%mod;

    ans *= (r-x+1);
    ans %= mod;
    ans *= (c-y+1);
    ans %= mod;

    cout << ans << endl;

    return 0;
}