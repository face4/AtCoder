#include<iostream>
#include<vector>
using namespace std;
const int mod = 1000000007;

int main(){
    int n;
    cin >> n;
    int a[n][n];
    for(int i = 0; i < n*n; i++)    cin >> a[i/n][i%n];
    vector<int> dp(1<<n, 0);
    dp.back() = 1;
    vector<int> pop(1<<n, n);
    for(int i = 0; i < 1<<n; i++){
        for(int j = 0; j < n; j++)  pop[i] -= (i>>j)&1;
    }
    for(int i = 0; i < n; i++){
        vector<int> ndp(1<<n, 0);
        for(int j = 0; j < 1<<n; j++){
            if(pop[j] != i) continue;
            for(int k = 0; k < n; k++){
                if(a[i][k] && (j>>k)&1) ndp[j^(1<<k)] = (ndp[j^(1<<k)]+dp[j])%mod;
            }
        }
        dp = ndp;
    }
    cout << dp[0] << endl;
    return 0;
}
