#include<iostream>
#include<vector>
#include<climits>
using namespace std;

const int INF = 1<<30;
int cost[301][301] = {};
int n, m, u, v, l;

int main(){
    cin >> n >> m;

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            if(i == j)  continue;
            cost[i][j] = INF;
        }
    }

    vector<int> one;
    for(int i = 0; i < m; i++){
        cin >> u >> v >> l;
        cost[u][v] = cost[v][u] = l;
        if(u == 1) one.push_back(v); 
    }

    for(int k = 2; k <= n; k++){
        for(int i = 2; i <= n; i++){
            for(int j = 2; j <= n; j++){
                if(cost[i][k] == INF || cost[k][j] == INF)  continue;
                cost[i][j] = min(cost[i][j], cost[i][k]+cost[k][j]);
            }
        }
    }

    int ans = INT_MAX;
    for(int i = 0; i < one.size()-1; i++){
        for(int j = i+1; j < one.size(); j++){
            if(cost[one[i]][one[j]] != INF){
                ans = min(ans, cost[1][one[i]] + cost[one[j]][1] + cost[one[i]][one[j]]);
            }
        }
    }

    cout << (ans == INT_MAX ? -1 : ans) << endl;
}