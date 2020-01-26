// editorialを読んだ
// 多倍長を使わなくても解ける様に考察する力が無かった
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<list>
using namespace std;
typedef long long ll;

const int mod = 1000000007;

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
    int n, a, b;
    cin >> n >> a >> b;
    multiset<ll> m;
    for(int i = 0; i < n; i++){
        int x;  cin >> x;
        m.insert(x);
    }
    if(a == 1){
        for(ll x : m)   cout << x%mod << endl;
        return 0;
    }
    while(b > 0 && *m.begin() * a < *m.rbegin()){
        b--;
        ll x = *m.begin();  m.erase(m.begin());
        m.insert(x*a);
    }
    list<ll> ans;
    for(ll x : m)   ans.push_back(x);
    for(auto it = ans.begin(); it != ans.end(); it++){
        *it = *it * modpow(a, b/n, mod) % mod;
    }
    for(int i = 0; i < b%n; i++){
        ll x = *ans.begin();    ans.pop_front();
        ans.push_back(x*a%mod);
    }
    for(ll x : ans) cout << x << endl;
    return 0;
}