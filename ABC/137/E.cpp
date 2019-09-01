#include<iostream>
#include<vector>
#include<climits>
#include<queue>
using namespace std;

struct edge{
    int from, to, cost;
};

int main(){
    int n, m, p;
    cin >> n >> m >> p;
    vector<edge> v;
    vector<int> fwd[n], rev[n];
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back(edge({--a, --b, -(c-p)}));
        fwd[a].push_back(b);
        rev[b].push_back(a);
    }
    vector<bool> a(n, 0), b(n, 0);
    a[0] = b[n-1] = true;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int x = q.front();  q.pop();
        for(int y : fwd[x]){
            if(!a[y]){
                a[y] = true;
                q.push(y);
            }
        }
    }
    q.push(n-1);
    while(!q.empty()){
        int x = q.front();  q.pop();
        for(int y : rev[x]){
            if(!b[y]){
                b[y] = true;
                q.push(y);
            }
        }
    }

    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < m; j++){
            int from = v[j].from, to = v[j].to;
            if(dp[from] != INT_MAX && dp[from]+v[j].cost < dp[to]){
                dp[to] = dp[from]+v[j].cost;
            }
        }
    }
    bool valid = true;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int from = v[j].from, to = v[j].to;
            if(dp[from] != INT_MAX && dp[from]+v[j].cost < dp[to]){
                dp[to] = dp[from]+v[j].cost;
                if(a[to] && b[to])   valid = false;
            }
        }
    }

    if(valid){
        cout << max(0, -dp[n-1]) << endl;
    }else{
        cout << -1 << endl;
    }
    return 0;
}