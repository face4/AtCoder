#include<iostream>
#include<vector>
#include<numeric>
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

vector<int> inv(200001), two(200001);
vector<int> v[200000], child[200000];
int n;

int dfs(int x, int p){
    for(int j : v[x]){
        if(j == p)  continue;
        child[x].push_back(dfs(j, x));
    }
    int sum = 1;
    for(int j : child[x])   sum += j;
    return sum;
}

int main(){
    cin >> n;
    inv[0] = 1;
    two[0] = 1;
    ll tinv = modpow(2, mod-2, mod);
    for(int i = 1; i <= n; i++) inv[i] = inv[i-1]*tinv%mod, two[i] = two[i-1]*2%mod;

    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(0, -1);

    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(child[i].empty() || child[i][0] == n-1)  continue;
        ll sub = 1;
        int res = n-1;
        for(int j : child[i]){
            res -= j;
            sub += (two[j]-1+mod)%mod;
            sub %= mod;
        }
        if(res) (sub += (two[res]-1+mod)%mod) %= mod;
        sub = (two[n-1]-sub+mod)%mod;
        (sub *= inv[n-1]) %= mod;
        (ans += sub*inv[1]%mod) %= mod;
    }
    cout << ans << endl;
    return 0;
}