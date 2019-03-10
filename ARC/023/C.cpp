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
        return (a%p * modpow(a, b-1, p)) % p;
    }
}

int main(){
    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i < n; i++)  cin >> a[i];

    auto f = [](ll n, ll k)->ll{
        ll ret = 1;
        for(int i = 0; i < k; i++){
            ret *= n-i;
            ret %= mod;
            ret *= modpow(i+1, mod-2, mod);
            ret %= mod;
        }
        return ret;
    };

    ll ans = 1;
    int cur = 1;
    while(cur+1 < n){
        if(a[cur] != -1){
            cur++;
            continue;
        }
        int l = a[cur-1];
        int to = cur;
        while(a[to] == -1) to++;
        int r = a[to];
        ans *= f(r-l+to-cur, to-cur);
        ans %= mod;
        cur = to;
    }

    cout << ans << endl;

    return 0;
}