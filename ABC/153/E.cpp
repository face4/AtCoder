#include<iostream>
#include<cstring>
using namespace std;

int dp[25000];

int main(){
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    int h, n;
    cin >> h >> n;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        for(int j = a; j < 24000; j++){
            if(dp[j-a] < 1e9)   dp[j] = min(dp[j], dp[j-a]+b);
        }
    }
    int ret = 1<<30;
    for(int j = h; j <= 22000; j++) ret = min(ret, dp[j]);
    cout << ret << endl;
    return 0;
}