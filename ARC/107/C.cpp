#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
const ll mod = 998244353;

struct UF{
    vector<int> p;
    int n;

    UF(int siz){
        n = siz;
        p.resize(n, 0);
        for(int i = 0; i < n; i++)  p[i] = i;
    }

    int parent(int x){
        if(p[x] != x)   p[x] = parent(p[x]);
        return p[x];
    }

    bool same(int x, int y){
        return parent(x) == parent(y);
    }
    
    void unite(int x, int y){
        x = parent(x), y = parent(y);
        p[x] = y;
    }
};

int main(){
    int n, x;
    cin >> n >> x;
    int a[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    UF var(n), hor(n);
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            bool vok = true, hok = true;
            for(int k = 0; k < n; k++){
                vok &= a[i][k]+a[j][k] <= x;
                hok &= a[k][i]+a[k][j] <= x;
            }
            if(vok) var.unite(i, j);
            if(hok) hor.unite(i, j);
        }
    }
    vector<int> vv(n, 0), hh(n, 0);
    for(int i = 0; i < n; i++)  vv[var.parent(i)]++, hh[hor.parent(i)]++;
    vector<ll> fact(n+1, 1);
    for(int i = 1; i <= n; i++) fact[i] = fact[i-1]*i%mod;
    ll vval = 1, hval = 1;
    for(int i = 0; i < n; i++)  (vval *= fact[vv[i]]) %= mod, (hval *= fact[hh[i]]) %= mod;
    cout << vval*hval%mod << endl;
    return 0;
}