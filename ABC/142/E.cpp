#include<iostream>
#include<vector>
using namespace std;

const int INF = 1e9+7;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> dp(1<<n, INF);
    dp[0] = 0;
    for(int i = 0; i < m; i++){
        vector<int> next = dp;
        int a, b;
        cin >> a >> b;
        int bit = 0;
        while(b-- > 0){
            int x;  cin >> x;
            x--;
            bit += (1<<x);
        }
        for(int j = 0; j < 1<<n; j++){
            next[j|bit] = min(next[j|bit], next[j] + a);
        }
        dp = next;
    }
    cout << (dp[(1<<n)-1]==INF ? -1 : dp[(1<<n)-1]) << endl;
    return 0;
}