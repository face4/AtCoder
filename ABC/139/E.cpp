#include<iostream>
#include<vector>
#include<queue>
#include<numeric>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n-1));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-1; j++){
            cin >> v[i][j];
            v[i][j]--;
        }
    }
    vector<vector<int>> num(n, vector<int>(n));
    int k = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            num[i][j] = num[j][i] = k++;
        }
    }
    vector<int> edge[k], indeg(k, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j+1 < n-1; j++){
            int ida = num[i][v[i][j]], idb = num[i][v[i][j+1]];
            bool found = false;
            for(int x : edge[ida])  found |= x==idb;
            if(found)   continue;
            edge[ida].push_back(idb);
            indeg[idb]++;
        }
    }
    queue<pair<int,int>> q;
    for(int i = 0; i < k; i++){
        if(indeg[i] == 0)   q.push({i, 1});
    }
    int ans;
    while(!q.empty()){
        auto p = q.front(); q.pop();
        ans = p.second;
        for(int next : edge[p.first]){
            indeg[next]--;
            if(indeg[next] == 0){
                q.push({next, ans+1});
            }
        }
    }
    cout << (accumulate(indeg.begin(), indeg.end(), 0ll) == 0 ? ans : -1) << endl;
    return 0;
}