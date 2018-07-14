#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int p[n+1], q[n+1];
    p[0] = q[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> p[i];
        q[p[i]] = i;
    }  

    int dp[n+1]; dp[0] = 0;
    for(int i = 1; i <= n; i++){
        if(q[p[i]-1] < i){
            dp[i] = dp[q[p[i]-1]]+1;
        }else{
            dp[i] = 1;
        }
    }

    int ans = -1;
    for(int i = 1; i <= n; i++) ans = max(ans, dp[i]);

    cout << n-ans << endl;
    return 0;
}