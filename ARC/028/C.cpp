#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int> v[100000], cnt(100000, 1);

int dfs(int cur){
    for(int child : v[cur]) cnt[cur] += dfs(child);
    return cnt[cur];
}

int main(){
    cin >> n;
    for(int i = 1; i < n; i++){
        int x;  cin >> x;
        v[x].push_back(i);
    }
    dfs(0);
    for(int i = 0; i < n; i++){
        int sum = 1, ma = 0;
        for(int child : v[i]){
            sum += cnt[child];
            ma = max(ma, cnt[child]);
        }
        ma = max(ma, n-sum);
        cout << ma << endl;
    }
    return 0;
}