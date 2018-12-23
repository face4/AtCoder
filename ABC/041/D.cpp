#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> va[n];
    int x, y;
    for(int i = 0; i < m; i++){
        cin >> x >> y;
        x--, y--;
        va[x].push_back(y);
    }

    vector<ll> dp(1<<n, 0);
    dp[0] = 1;

    for(int s = 0; s < 1<<n; s++){
        for(int i = 0; i < n; i++){
            if(s & (1<<i))  continue;
            bool judge = true;
            for(int next : va[i]){
                if(s & (1<<next)){
                    judge = false;
                    break;
                }
            }
            if(!judge)  continue;
            dp[s|(1<<i)] += dp[s];
        }
    }

    cout << dp[(1<<n)-1] << endl;
    
    return 0;
}