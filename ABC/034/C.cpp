#include<iostream>
using namespace std;

typedef long long ll;

ll powerInMod(ll a, ll b, ll p){
    if(b == 0)  return 1;

    if(b % 2 == 0){
        ll d = powerInMod(a, b/2, p);
        return (d*d) % p;
    }else{
        return (a * powerInMod(a, b-1, p)) % p;
    }
}

ll nCm(ll n, ll m, ll p){
    ll ret = 1;
    
    // nCm == nC(n-m)
    if(m > n/2) m = n-m;

    for(ll i = 1; i <= m; i++){
        ret *= n-(i-1);
        ret %= p;
        ret *= powerInMod(i, p-2, p);
        ret %= p;
    }
    
    return ret;
}

int main(){
    ll w, h;
    cin >> w >> h;

    cout << nCm(w+h-2, h-1, 1000000007) << endl;
    
    return 0;
}