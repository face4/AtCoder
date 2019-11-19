// modKで同一視出来ることに気が付けるようになりたい
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main(){
    int k;
    cin >> k;
    vector<int> dp(k, 1<<30);
    deque<int> d;
    d.push_front(1);
    dp[1] = 0;
    while(!d.empty()){
        int x = d.front();  d.pop_front();
        if(dp[10*x%k] > dp[x])      dp[10*x%k] = dp[x], d.push_front(10*x%k);
        if(dp[(x+1)%k] > dp[x]+1)   dp[(x+1)%k] = dp[x]+1, d.push_back((x+1)%k);
    }
    cout << 1+dp[0] << endl;
    return 0;
}