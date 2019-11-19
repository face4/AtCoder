// サンプルは合う
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main(){
    int n, m;
    cin >> n >> m;
    vector<pii> vp[n+1];
    while(m-- > 0){
        int l, r, c;
        cin >> l >> r >> c;
        vp[l].push_back({r,c});
    }
    vector<ll> dp(n+1, 1ll<<60);
    dp[0] = 0;
    priority_queue<pair<ll,int>> pq;
    for(pii p : vp[1]){
        pq.push({-(dp[1-1]+p.second), p.first});
    }
    for(int i = 1; i <= n; i++){
        while(!pq.empty() && pq.top().second < i)  pq.pop();
        if(pq.empty()){
            cout << -1 << endl;
            return 0;
        }
        dp[i] = -pq.top().first;
        if(i != 1){
            for(pii p : vp[i]){
                pq.push({-(dp[i]+p.second), p.first});
            }
        }
    }
    cout << dp[n] << endl;
    return 0;
}