#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> v[n];
    int a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        a--, b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i = 0; i < n; i++){
        vector<bool> visit(n, 0);
        int ans = 0;
        queue<pair<int,int>> q;
        q.push({0, i});
        while(!q.empty()){
            pair<int,int> p = q.front(); q.pop();
            if(visit[p.second]) continue;
            if(p.first == 2)    ans++;
            visit[p.second] = true;
            for(int next : v[p.second]) if(!visit[next])    q.push({p.first+1,next});
        }
        cout << ans << endl;
    }

    return 0;
}