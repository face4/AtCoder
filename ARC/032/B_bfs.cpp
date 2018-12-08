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

    vector<bool> visit(n, 0);
    int ans = -1; // 欲しいのは連結成分の個数-1
    for(int i = 0; i < n; i++){
        if(visit[i])    continue;
        ans++;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int x = q.front();  q.pop();
            visit[x] = true;
            for(int next : v[x])    if(!visit[next])    q.push(next);
        }
    }

    cout << ans << endl;

    return 0;
}
