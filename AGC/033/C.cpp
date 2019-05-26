#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// 1度の操作で葉を選べば直径が1減り、葉以外を選べば直径が2減る
// よってmod3の世界で考えれば良く、mod3==1で自分に手番が回ってきた
// 時に確実に負けるので、初期状態で木の直径のmod3==1なら先手の負け、
// それ以外なら先手の勝ち

int main(){
    int n;
    cin >> n;
    vector<int> v[n];
    int a, b;
    for(int i = 1; i < n; i++){
        cin >> a >> b;
        a--, b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    queue<int> q;
    q.push(0);
    int x;
    vector<bool> visit(n, 0);
    while(!q.empty()){
        int i = q.front();  q.pop();
        if(visit[i])    continue;
        visit[i] = true;
        x = i;
        for(int next : v[i]){
            if(!visit[next]){
                q.push(next);
            }
        }
    }
    queue<pair<int,int>> pq;
    pq.push({x,0});
    for(int i = 0; i < n; i++)  visit[i] = 0;
    int diam;
    while(!pq.empty()){
        auto p = pq.front();    pq.pop();
        int i = p.first, j = p.second;
        if(visit[i])    continue;
        visit[i] = true;
        diam = j;
        for(int next : v[i]){
            if(!visit[next]){
                pq.push({next, j+1});
            }
        }
    }
    cout << (diam%3 == 1 ? "Second" : "First") << endl;
    return 0;
}