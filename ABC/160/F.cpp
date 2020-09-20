#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
ll f[200001], finv[200001], dp[200001], ans[200001];
int child[200001];
const ll mod = 1000000007;

ll modpow(ll a, ll b, ll p = 1e9+7){
    if(b == 0)  return 1;

    if(b % 2 == 0){
        ll d = modpow(a, b/2, p);
        return (d*d) % p;
    }else{
        return (a%p * modpow(a, b-1, p)) % p;
    }
}

vector<int> v[200001];
int n;

void dfs(int p, int x){
    child[x] = 1;
    for(int j : v[x]){
        if(j == p)  continue;
        dfs(x, j);
        child[x] += child[j];
    }
    dp[x] = f[child[x]-1];
    for(int j : v[x]){
        if(j == p)  continue;
        dp[x] = dp[x]*finv[child[j]]%mod*dp[j]%mod;
    }
}

void dfs2(int p, int x){
    for(int j : v[x]){
        if(j == p)  continue;
        ans[j] = ans[x]*f[n-1-child[j]]%mod*f[child[j]]%mod*modpow(dp[j], mod-2)%mod*finv[n-child[j]]%mod;
        for(int k : v[j]){
            if(k == x)  continue;
            ans[j] = ans[j]*finv[child[k]]%mod*dp[k]%mod;
        }
        dfs2(x, j);
    }
}

int main(){
    f[0] = finv[0] = 1;
    for(int i = 1; i <= 200000; i++){
        f[i] = f[i-1]*i%mod;
    }
    finv[200000] = modpow(f[200000], mod-2);
    for(int i = 199999; i >= 1; i--){
        finv[i] = finv[i+1]*(i+1)%mod;
    }

    cin >> n;
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(0, 1);
    ans[1] = dp[1];
    dfs2(0, 1);
    for(int i = 1; i <= n; i++) cout << ans[i] << endl;
    return 0;
}