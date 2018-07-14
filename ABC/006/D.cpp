#include<iostream>
using namespace std;

const int INF = 1<<21;

int main(){
    int n;
    cin >> n;

    int c[n];
    for(int i = 0; i < n; i++)  cin >> c[i];

    int dp[n];
    for(int i = 0; i < n; i++)  dp[i] = INF;

    for(int i = 0; i < n; i++){
        *lower_bound(dp, dp+n, c[i]) = c[i];
    }

    cout << n-(int)(lower_bound(dp, dp+n, INF) - dp) << endl;

    return 0;
}