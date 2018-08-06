#include<iostream>
using namespace std;

int dp[8][100];
int INF = 100;
int dx[6] = {-10, -5, -1, 1, 5, 10};

int main(){
    int a, b;
    cin >> a >> b;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 100; j++){
            dp[i][j] = INF;
        }
    }
    dp[0][50+a] = 0;

    for(int i = 1; i < 8; i++){
        for(int j = 0; j < 100; j++){
            if(dp[i-1][j] != INF){
                dp[i][j] = min(dp[i][j], dp[i-1][j]);
                for(int k = 0; k < 6; k++){
                    int next = j+dx[k];
                    if(0 <= next && next < 100){
                        dp[i][next] = min(dp[i][next], dp[i-1][j]+1);
                    }
                }
            }
        }
    }

    cout << dp[7][50+b] << endl;

    return 0;
}