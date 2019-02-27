#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> a(n), ans(n);
    for(int i = 0; i < n; i++)  a[i] = i;
    vector<int> b(m);
    for(int i = 0; i < m; i++)  cin >> b[i];
    for(int i = m-1; i >= 0; i--){
        swap(a[b[i]-1], a[b[i]]);
    }
    vector<bool> visit(n);
    for(int i = 0; i < n; i++){
        if(visit[i])    continue;
        vector<int> v;
        int now = i;
        while(!visit[now]){
            visit[now] = true;
            v.push_back(now);
            now = a[now];
        }
        for(int j = 0; j < v.size(); j++){
            ans[v[j]] = v[(j+d)%v.size()]+1;
        }
    }
    for(int i = 0; i < n; i++)  cout << ans[i] << endl;
    return 0;
}