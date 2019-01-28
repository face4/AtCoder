// DAG
#include<iostream>
#include<map>
#include<stack>
#include<vector>
#include<set>
#include<queue>
using namespace std;

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    vector<int> edge[n+1];
    vector<int> indeg(n+1, 0);

    int a, b;
    for(int i = 0; i < n+m-1; i++){
        scanf("%d %d", &a, &b);
        indeg[b]++;
        edge[a].push_back(b);
    }

    vector<int> ans(n+1, 0);
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(indeg[i] == 0)   q.push({i});
    }

    while(!q.empty()){
        int now = q.front();    q.pop();
        for(int next : edge[now]){
            indeg[next]--;
            if(indeg[next] == 0){
                ans[next] = now;
                q.push(next);
            }
        }
    }
    
    for(int i = 1; i <= n; i++) printf("%d\n", ans[i]);

    return 0;
}