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
    int n;
    ll k;
    cin >> n >> k;
    mat v(n, vec(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> v[i][j];
        }
    }
    v = pow(v, k);
    ll ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ans += v[i][j];
            ans %= mod;
        }
    }
    cout << ans << endl;
    return 0;
}