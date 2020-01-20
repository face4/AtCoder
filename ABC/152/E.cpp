#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
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

const int mod = 1000000007;

int main(){
    int n;
    cin >> n;
    vector<ll> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i];
    map<int,int> fact;
    for(int i = 0; i < n; i++){
        int cp = v[i];
        for(int i = 2; i*i <= cp; i++){
            if(cp%i)    continue;
            int cnt = 0;
            while(cp%i == 0)    cp /= i, cnt++;
            if(fact[i] < cnt)   fact[i] = cnt;
        }
        if(cp != 1 && fact.count(cp) == 0)  fact[cp] = 1;
    }
    ll all = 1;
    for(auto p : fact){
        int times = p.second;
        while(times--)  (all *= p.first) %= mod;
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans += all*modpow(v[i],mod-2,mod);
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}