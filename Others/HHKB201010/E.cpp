#include<iostream>
#include<vector>
using namespace std;

int up[2000][2000]={};
int down[2000][2000]={};
int rg[2000][2000]={};
int lf[2000][2000]={};

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
const ll mod = 1e9+7;

int main(){
    int h, w;
    cin >> h >> w;
    char mat[h][w];
    int l = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> mat[i][j];
            l += mat[i][j]=='.';
        }
    }
    for(int j = 0; j < w; j++)  down[0][j] = mat[0][j]=='.', up[h-1][j]=mat[h-1][j]=='.';
    for(int i = 1; i < h; i++){
        for(int j = 0; j < w; j++){
            if(mat[i][j]=='.')          down[i][j]=down[i-1][j]+1;
            if(mat[h-1-i][j]=='.')      up[h-1-i][j]=up[h-i][j]+1;
        }
    }
    for(int i = 0; i < h; i++)  rg[i][0] = mat[i][0]=='.', lf[i][w-1]=mat[i][w-1]=='.';
    for(int j = 1; j < w; j++){
        for(int i = 0; i < h; i++){
            if(mat[i][j]=='.')          rg[i][j] = rg[i][j-1]+1;
            if(mat[i][w-1-j]=='.')      lf[i][w-1-j] = lf[i][w-j]+1;
        }
    }
    ll ans = 0, all = modpow(2, l);
    vector<ll> memo(l+1, 1);
    for(int i = 1; i <= l; i++) memo[i] = memo[i-1]*2%mod;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(mat[i][j] == '#')    continue;
            ll vacant = up[i][j]+down[i][j]+rg[i][j]+lf[i][j]-3;
            ans += all-memo[l-vacant]+mod;
            ans %= mod;
        }
    }
    cout << ans << endl;
    return 0;
}