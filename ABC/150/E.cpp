#include<iostream>
#include<vector>
#include<algorithm>
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
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i];
    sort(v.begin(), v.end());
    vector<ll> two(n+1, 1), four(n+1, 1);
    for(int i = 1; i <= n; i++){
        two[i] = two[i-1]*2%mod;
        four[i] = four[i-1]*4%mod;
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ll tmp = two[n-1-i]*four[i+1]%mod;
        int x = n-i-1+1;
        ll y = two[x-1]+ (x-1)*(x-2 >= 0 ? two[x-2] : 0);
        y %= mod;
        ans += v[i]*tmp%mod*y%mod;
        ans %= mod;
    }
    cout << ans*modpow(2,mod-2,mod)%mod << endl;
    return 0;
}