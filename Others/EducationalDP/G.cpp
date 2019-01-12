#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> dp(n, 0), child[n], indeg(n, 0);
    int x, y;

    for(int i = 0; i < m; i++){
        cin >> x >> y;
        x--, y--;
        child[x].push_back(y);
        indeg[y]++;
    }

    queue<pair<int,int>> q;
    vector<double> used(n, 0);

    for(int i = 0; i < n; i++)  if(indeg[i] == 0)   q.push({i, 0});

    while(!q.empty()){
        pair<int,int> p = q.front();    q.pop();
        dp[p.first] = p.second;
        used[p.first] = true;
        for(int c : child[p.first]){
            indeg[c]--;
            if(indeg[c] == 0)   q.push({c, dp[p.first]+1});
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << endl;

    return 0;
}