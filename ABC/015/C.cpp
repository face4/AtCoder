#include<iostream>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    int t[n][k];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++){
            cin >> t[i][j];
        }
    }

    bool dp[n+1][128];
    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < 128; j++){
            dp[i][j] = false;
        }
    }

    dp[0][0] = true;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 128; j++){
            if(dp[i][j]){
                for(int l = 0; l < k; l++){
                    dp[i+1][j^t[i][l]] = true;
                }
            }
        }
    }

    if(dp[n][0])    cout << "Found" << endl;
    else            cout << "Nothing" << endl;
    
    return 0;
}