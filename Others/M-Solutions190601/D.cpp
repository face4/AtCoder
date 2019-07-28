#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

// ?
int main(){
    int n;
    cin >> n;
    vector<int> a(n-1), b(n-1), deg(n,0), v[n];
    for(int i = 0; i < n-1; i++){
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
        v[a[i]].push_back(b[i]);
        v[b[i]].push_back(a[i]);
        deg[a[i]]++, deg[b[i]]++;
    }
    vector<int> c(n);
    for(int i = 0; i < n; i++)  cin >> c[i];
    sort(c.begin(), c.end());
    int pos = 0;
    queue<int> q;
    vector<int> w(n, 0);
    for(int i = 0; i < n; i++)  if(deg[i] == 1) q.push(i);
    while(!q.empty()){
        int p = q.front();  q.pop();
        if(w[p] != 0) continue;
        w[p] = c[pos++];
        for(int next : v[p]){
            deg[next]--;
            if(deg[next] == 1)  q.push(next);
        }
    }
    int ans = 0;
    for(int i = 0; i < n-1; i++){
        ans += min(w[a[i]], w[b[i]]);
    }
    cout << ans << endl;
    for(int i = 0; i < n; i++)  cout << w[i] << " \n"[i==n-1];
    return 0;
}