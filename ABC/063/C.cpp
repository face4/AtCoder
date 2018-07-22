#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    bool dp[101][10001] = {};
    dp[0][0] = true;

    int x;
    for(int i = 0; i < n; i++){
        cin >> x;

        for(int j = 0; j <= 10000; j++){
            if(dp[i][j]){
                dp[i+1][j] = true;
                if(j + x <= 10000){
                    dp[i+1][j+x] = true;
                }
            }
        }

    }

    for(int j = 10000; j > 0; j--){
        if(dp[n][j] && j % 10 != 0){
            cout << j << endl;
            return 0;
        }
    }

    cout << 0 << endl;
    return 0;
}