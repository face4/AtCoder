#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
ll mod = 1000000007;

mat mul(mat &A, mat &B){
    mat C(A.size(), vec(B[0].size()));
    for(int i = 0; i < A.size(); i++){
        for(int k = 0; k < B.size(); k++){
            for(int j = 0; j < B[0].size(); j++){
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
            }
        }
    }
    return C;
}

mat pow(mat A, ll n){
    mat B(A.size(), vec(A.size()));
    for(int i = 0; i < A.size(); i++){
        B[i][i] = 1ll;
    }
    while(n > 0){
        if(n & 1)   B = mul(B, A);
        A = mul(A, A);
        n >>= 1;
    }
    return B;
}

int main(){
    int h, r;
    cin >> h >> r;
    int g[r][r];
    for(int i = 0; i < r; i++){
        for(int j = 0; j < r; j++){
            cin >> g[i][j];
        }
    }
    mat A(r, vec(r, 0));
    for(int x = 0; x < r; x++){
        vector<vector<ll>> dp(r, vector<ll>(1<<r,0));
        dp[x][1<<x] = 1;
        for(int s = 0; s < 1<<r; s++){
            for(int i = 0; i < r; i++){
                if(((s>>i)&1) == 0)   continue;
                if(dp[i][s] == 0)   continue;
                for(int j = 0; j < r; j++){
                    if((s>>j)&1)    continue;
                    if(g[i][j] == 0)    continue;
                    int nbit = s|(1<<j);
                    dp[j][nbit] = (dp[j][nbit]+dp[i][s])%mod;
                }
            }
        }
        for(int i = 0; i < r; i++){
            for(int j = 0; j < 1<<r; j++){
                A[i][x] = (A[i][x]+dp[i][j])%mod;
            }
        }
    }
    mat x(r, vec(1,0));
    x[0][0] = 1;
    mat res = pow(A, h);
    res = mul(res, x);
    cout << res[0][0] << endl;
    return 0;
}
