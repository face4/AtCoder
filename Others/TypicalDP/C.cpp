#include<iostream>
#include<iomanip>
#include<vector>
#include<cmath>
using namespace std;

double win(double x, double y){
    return 1.0 / (1 + pow(10, (y-x)/400));
}

int main(){
    int k;
    cin >> k;
    vector<int> v(1<<k);
    for(int i = 0; i < 1<<k; i++)   cin >> v[i];
    vector<vector<double>> dp(k+1, vector<double>(1<<k, 0));
    fill(dp[0].begin(), dp[0].end(), 1.0);
    for(int i = 0; i < k; i++){
        for(int j = 0; j < 1<<k; j++){
            int from;
            int pos = j%(1<<(i+1));
            if(pos < 1<<i){
                from = j/(1<<(i+1))*(1<<(i+1))+(1<<i);
            }else{
                from = j/(1<<(i+1))*(1<<(i+1));
            }
            for(int opp = from; opp < from+(1<<i); opp++){
                dp[i+1][j] += dp[i][j]*dp[i][opp]*win(v[j], v[opp]);
            }
        }
    }
    cout << fixed << setprecision(12);
    for(int i = 0; i < 1<<k; i++)   cout << dp[k][i] << endl;
    return 0;
}