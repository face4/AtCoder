#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main(){
    int n, m, s;
    cin >> n >> m >> s;
    s--;
    vector<int> v[n];
    int a, b;
    while(m-- > 0){
        cin >> a >> b;
        a--, b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<int> d(n, -1);
    int ans = 0;
    priority_queue<pair<int,int>> pq;
    pq.push({s, s});
    while(!pq.empty()){
        pair<int,int> p = pq.top(); pq.pop();
        int c = p.first, now = p.second;
        if(d[now] > c)  continue;
        d[now] = c;
        for(int next : v[now]){
            if(min(c, now) > d[next]) pq.push({min(c,now), next});
        }
    }
    for(int i = 0; i < n; i++){
        if(d[i] >= i)   cout << i+1 << endl;
    }
    return 0;
}