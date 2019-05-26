#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;
typedef long long ll;

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    map<int,vector<int>> v[n];
    int p, q, c;
    while(m-- > 0){
        scanf("%d %d %d", &p, &q, &c);
        p--, q--;
        v[p][c].push_back(q);
        v[q][c].push_back(p);
    }
    
    // pos, kind
    map<int,int> dp[n];
    
    // cost, pos, kind
    priority_queue<pair<int,pair<int,int>>> pq;
    pq.push({-1, {0, 0}});
    while(!pq.empty()){
        auto p = pq.top();  pq.pop();
        int cost = -p.first, pos = p.second.first, kind = p.second.second;
        if(kind == 0){
            for(auto q : v[pos]){
                int kind = q.first;
                for(int next : q.second){
                    if(dp[next].count(kind) == 0){
                        dp[next][kind] = cost;
                        pq.push({-cost, {next,kind}});
                    }
                }
            }
        }else{
            if(dp[pos].count(0) == 0){
                dp[pos][0] = cost+1;
                pq.push({-(cost+1), {pos, 0}});
            }
            for(int next : v[pos][kind]){
                if(dp[next].count(kind) == 0){
                    dp[next][kind] = cost;
                    pq.push({-cost, {next,kind}});
                }
            }
        }
    }

    int ans = 1<<30;
    for(auto p : dp[n-1]){
        ans = min(ans, p.second);
    }

    cout << (ans == 1<<30 ? -1 : ans) << endl;

    return 0;
}
