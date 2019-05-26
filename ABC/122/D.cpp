#include<iostream>
using namespace std;
const int mod = 1e9 + 7;

string ff(int i, int j, int k, int l){
    string s = "";
    s += "ACGT"[i];
    s += "ACGT"[j];
    s += "ACGT"[k];
    s += "ACGT"[l];
    return s;
}

int main(){
    int n;
    cin >> n;
    if(n == 3){
        cout << 61 << endl;
        return 0;
    }
    int no[3] = {0,2,1};
    int dp[4][4][4][101] = {};
    auto f = [=](int i, int j, int k)->bool{
        bool ret = false;
        if(i==no[0]&&j==no[1]&&k==no[2])   ret = true;
        return ret;
    };
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 4; k++){
                for(int l = 0; l < 4; l++){
                    bool ok = true;
                    if(f(i,j,k) || f(j,k,l))    ok = false;
                    swap(i,j);
                    if(f(i,j,k) || f(j,k,l))    ok = false;
                    swap(i,j); swap(j,k);
                    if(f(i,j,k) || f(j,k,l))    ok = false;
                    swap(j,k);  swap(k,l);
                    if(f(i,j,k) || f(j,k,l))    ok = false;
                    swap(k,l);
                    if(ok)  dp[j][k][l][3]++;
                }
            }
        }
    }

    for(int x = 3; x < n-1; x++){
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                for(int k = 0; k < 4; k++){
                    for(int l = 0; l < 4; l++){
                        bool ok = true;
                        if(f(i,j,k) || f(j,k,l))    ok = false;
                        swap(i,j);
                        if(f(i,j,k) || f(j,k,l))    ok = false;
                        swap(i,j); swap(j,k);
                        if(f(i,j,k) || f(j,k,l))    ok = false;
                        swap(j,k);  swap(k,l);
                        if(f(i,j,k) || f(j,k,l))    ok = false;
                        swap(k,l);
                        if(ok)  dp[j][k][l][x+1] += dp[i][j][k][x], dp[j][k][l][x+1]%=mod;
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 4; k++){
                ans += dp[i][j][k][n-1];
                ans %= mod;
            }
        }
    }
    cout << ans << endl;
    return 0;
}