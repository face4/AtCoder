#include<iostream>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    bool dp[n+1][128];
    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < 128; j++){
            dp[i][j] = false;
        }
    }

    dp[0][0] = true;

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < k; j++){
            int t;
            cin >> t;

            for(int x = 0; x < 128; x++){
                if(dp[i-1][x])  dp[i][x^t] = true;
            }
        }
    }

    if(dp[n][0])    cout << "Found" << endl;
    else            cout << "Nothing" << endl;
    
    return 0;
}