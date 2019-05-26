#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

vector<int> ans, v[100000];
vector<bool> visit;

void dfs(int i){
    ans.push_back(i);
    visit[i] = true;
    for(int j : v[i]){
        if(visit[j])    continue;
        dfs(j);
        return;
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    int a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        a--, b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    visit.resize(n, 0);
    dfs(0);
    reverse(ans.begin(), ans.end());
    ans.pop_back(); // 賢い
    dfs(0); // 賢い
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) cout << ans[i]+1 << " \n"[i==ans.size()-1];
    return 0;
}