#include<iostream>
using namespace std;

bool dp[101][301] = {};
bool ng[301] = {};

int main(){
    dp[0][0] = true;
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    ng[a] = ng[b] = ng[c] = true;

    for(int i = 1; i <= 100; i++){
        for(int j = i-1; j <= 3*(i-1); j++){
            if(dp[i-1][j] && !ng[j]){
                for(int k = 1; k <= 3; k++){
                    if(!ng[j+k])    dp[i][j+k] = true;
                } 
            }    
        }
        for(int j = 0; j <= 300; j++){
            if(dp[i-1][j])  dp[i][j] = true;
        }
    }

    if(dp[100][n])  cout << "YES" << endl;
    else            cout << "NO" << endl;

    return 0;
}