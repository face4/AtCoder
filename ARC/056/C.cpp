// editorial
#include<iostream>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int w[n][n], sub = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> w[i][j];
            if(i < j)   sub += w[i][j];
        }
    }
    int bet[1<<n];
    for(int s = 0; s < 1<<n; s++){
        bet[s] = 0;
        for(int i = 0; i < n; i++){
            if((s>>i&1) == 0)   continue;
            for(int j = i+1; j < n; j++){
                if(s>>j&1)  bet[s] += w[i][j];
            }
        }
    }
    int dp[1<<n];
    dp[0] = 0;
    for(int s = 1; s < 1<<n; s++){
        dp[s] = 0;
        int partial = s;
        do{
            dp[s] = max(dp[s], dp[partial]+k-(bet[s]-bet[partial]-bet[s^partial]));
            partial = (partial-1)&s;
        }while(partial != s);
    }
    cout << dp[(1<<n)-1] << endl;
    return 0;
}