#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
ll mod = 998244353;

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
    ll n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i];
    vector<int> cnt(100001, 0);
    int to = 0;
    for(int i = 0; i < n; i++){
        if(i == 0 && v[i] != 0){
            cout << 0 << endl;
            return 0;
        }
        if(i != 0 && v[i] == 0){
            cout << 0 << endl;
            return 0;
        }
        cnt[v[i]]++;
        to = max(v[i], to);
    }
    ll ans = 1;
    for(int i = 1; i <= to; i++){
        for(int j = 0; j < cnt[i]; j++) ans = ans*cnt[i-1]%mod;
    }
    cout << ans << endl;
    return 0;
}