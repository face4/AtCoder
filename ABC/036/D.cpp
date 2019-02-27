#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

ll ff(int now, int par);
ll gg(int now, int par);

vector<int> v[100000], f(100000, 0), g(100000, 0);
ll ans = 0;

ll ff(int now, int par){
    if(f[now])  return f[now];
    ll ret = 1;
    for(int child : v[now]){
        if(child == par)   continue;
        ret *= gg(child, now);
        ret %= mod;
    }
    return f[now] = ret;
}

ll gg(int now, int par){
    if(g[now])  return g[now];
    g[now] += ff(now, par);

    ll add = 1;
    for(int child : v[now]){
        if(child == par)    continue;
        add *= ff(child, now);
        add %= mod;
    }
    
    g[now] += add;
    g[now] %= mod;

    return g[now];
}

int main(){
    int n, a, b;
    cin >> n;

    for(int i = 1; i < n; i++){
        cin >> a >> b;
        a--, b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    cout << gg(0,-1) << endl;

    return 0;
}