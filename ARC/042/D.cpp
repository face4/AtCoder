#include<iostream>
#include<map>
#include<set>
#include<cmath>
using namespace std;
typedef long long ll;

ll modpow(ll a, ll b, ll p = 1e9+7){
    if(b == 0)  return 1;

    if(b % 2 == 0){
        ll d = modpow(a, b/2, p);
        return (d*d) % p;
    }else{
        return (a%p * modpow(a, b-1, p)) % p;
    }
}

int bsgs(ll x, ll y, ll p, int n){
    int k = sqrt(n)+1;
    map<ll,int> m;
    ll tmp = 1;
    for(int i = 0; i < k; i++){
        (tmp *= x) %= p;
        if(m.count(tmp))    continue;
        m[tmp] = i+1;
    }
    ll invx = modpow(x, p-2, p);
    invx = modpow(invx, k, p);
    for(int i = 0; i < k; i++){
        if(m.count(y)){
            if(i*k+m[y] <= n)   return i*k+m[y];
        }
        (y *= invx) %= p;
    }
    return -1;
}

int main(){
    int x, p, a, b;
    cin >> x >> p >> a >> b;
    int n = b-a+1;
    if(a == 0){
        cout << 1 << endl;
    }else if(n < 1<<22){
        set<ll> app;
        ll k = modpow(x, a, p);
        app.insert(k);
        for(int i = 0; i < b-a; i++){
            (k *= x) %= p;
            app.insert(k);
        }
        cout << *app.begin() << endl;
    }else{
        ll invx = modpow(x, p-2, p);
        invx = modpow(invx, a-1, p);
        for(int i = 1;;i++){
            ll y = invx*i%p;
            if(bsgs(x, y, p, n) != -1){
                cout << i << endl;
                return 0;
            }
        }
    }
    return 0;
}