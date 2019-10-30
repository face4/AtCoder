#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    ll a[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    vector<ll> gr(1<<n, 0);
    for(int i = 0; i < 1<<n; i++){
        for(int j = 0; j < n; j++){
            if(((i>>j)&1) == 0)   continue;
            for(int k = j+1; k < n; k++){
                if(((i>>k)&1)==0)    continue;
                gr[i] += a[j][k];
            }
        }
    }
    vector<ll> dp(1<<n, 0);
    for(int i = 1; i < 1<<n; i++){
        int sub = i;
        do{
            dp[i] = max(dp[i], dp[i-sub]+gr[sub]);
            sub = (sub-1)&i;
        }while(sub != i);   // sub=-1のときsub&i==i
    }
    cout << dp.back() << endl;
    return 0;
}