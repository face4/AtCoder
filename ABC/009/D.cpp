#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

mat mul(mat &A, mat &B){
    mat C(A.size(), vec(B[0].size()));
    for(int i = 0; i < A.size(); i++){
        for(int k = 0; k < B.size(); k++){
            for(int j = 0; j < B[0].size(); j++){
                C[i][j] = C[i][j] ^ (A[i][k]&B[k][j]);
            }
        }
    }
    return C;
}

mat pow(mat A, ll n){
    mat B(A.size(), vec(A.size()));
    for(int i = 0; i < A.size(); i++)   B[i][i] = ~0;
    while(n > 0){
        if(n & 1)   B = mul(B, A);
        A = mul(A, A);
        n >>= 1;
    }
    return B;
}

// どうしてもバグるので他人の提出を参考にして修正,
// ~0 = (111111.....111)であることに気が付かなかった

int main(){
    int k, m;
    cin >> k >> m;
    vector<ll> a(k), c(k);
    for(int i = 0; i < k; i++)  cin >> a[i];
    for(int i = 0; i < k; i++)  cin >> c[i];
    if(m <= k){
        cout << a[m-1] << endl;
        return 0;
    }
    mat x(k, vec(1));
    for(int i = 0; i < k; i++){
        x[i][0] = a[k-1-i];
    }
    mat A(k, vec(k));
    for(int i = 0; i < k; i++)  A[0][i] = c[i];
    for(int i = 1; i < k; i++)  A[i][i-1] = ~0;
    A = pow(A, m-k);
    mat res = mul(A, x);
    cout << res[0][0] << endl;
    return 0;
}
