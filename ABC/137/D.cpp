#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> v[100001];
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    int ans = 0;
    priority_queue<int> pq;
    for(int i = 1; i <= m; i++){
        for(int j : v[i])   pq.push(j);
        if(pq.empty())  continue;
        ans += pq.top();
        pq.pop();
    }
    cout << ans << endl;
    return 0;
}