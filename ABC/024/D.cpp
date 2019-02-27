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
    ll a, b, c;
    cin >> a >> b >> c;

    ll ab = a*b%mod, bc = b*c%mod, ca = c*a%mod;

    ll ro = (bc-ca+mod)%mod*modpow((ab-bc+ca+mod)%mod, mod-2, mod)%mod;
    ll co = (bc-ab+mod)%mod*modpow((ca-bc+ab+mod)%mod, mod-2, mod)%mod;
    
    cout << ro << " " << co << endl;
    return 0;
}