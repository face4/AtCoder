#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int main(){
    string f, l;
    cin >> f >> l;

    int n;
    cin >> n;

    set<string> li;
    string s;
    for(int i = 0; i < n; i++){
        cin >> s;
        if(s == f || s == l)    continue;
        li.insert(s);
    }

    vector<string> v;
    v.push_back(f);
    for(set<string>::iterator it = li.begin(); it != li.end(); it++)  v.push_back(*it);
    v.push_back(l);

    if(f == l){
        cout << 0 << endl << f << endl << f << endl;
        return 0;
    }

    vector<int> path[v.size()], dist(v.size(), 10000), back(v.size(), -1);
    for(int i = 0; i < v.size(); i++){
        for(int j = i+1; j < v.size(); j++){
            int diff = 0;
            for(int k = 0; k < f.length(); k++){
                diff += (v[i][k] != v[j][k]);
            }
            if(diff == 1){
                path[i].push_back(j);
                path[j].push_back(i);
            }
        }
    }

    // parent, current, distance
    queue<pair<pair<int,int>,int>> q;
    q.push({{-1, 0},0});
    while(!q.empty()){
        auto p = q.front(); q.pop();
        int par = p.first.first, cur = p.first.second, d = p.second;
        if(d >= dist[cur])  continue;
        dist[cur] = d;
        back[cur] = par;
        for(int next : path[cur]){
            if(d+1 < dist[next])    q.push({{cur, next}, d+1});
        }
    }

    if(dist[v.size()-1] == 10000){
        cout << -1 << endl;
    }else{
        vector<int> ans;
        int cur = v.size()-1;
        while(cur != 0){
            ans.push_back(cur);
            cur = back[cur];
        }
        ans.push_back(0);
        reverse(ans.begin(), ans.end());
        cout << ans.size()-2 << endl;
        for(int i = 0; i < ans.size(); i++){
            cout << v[ans[i]] << endl;
        }
    }
    return 0;
}