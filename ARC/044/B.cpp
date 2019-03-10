#include<iostream>
#include<vector>
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
    vector<int> v(n), cnt(n, 0);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        cnt[v[i]]++;
    }

    if(cnt[0] != 1 || v[0] != 0){
        cout << 0 << endl;
        return 0;
    }
    ll ans = 1;
    for(int i = 1; i < n; i++){
        if(cnt[i]){
            ans *= modpow((modpow(2, cnt[i-1], mod)-1+mod)%mod, cnt[i], mod);
            ans %= mod;
            ans *= modpow(2, (ll)cnt[i]*(cnt[i]-1)/2, mod);
            ans %= mod;
        }
    }
    cout << ans << endl;
    return 0;
}