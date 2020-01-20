#include<iostream>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

vector<pii> v[100000];
vector<int> et, deepen;

void dfs(int x, int p){
    for(pii next : v[x]){
        if(next.first == p) continue;
        et.push_back(next.second);
        deepen.push_back(1);
        dfs(next.first, x);
        et.push_back(next.second);
        deepen.push_back(0);
    }
}

int main(){
    int n, x;
    cin >> n >> x;
    for(int i = 0; i < n-1; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    dfs(0, -1);
    ll ans = 0, cumxor = 0;
    map<int,int> memo;
    memo[0]++;
    for(int i = 0; i < et.size(); i++){
        cumxor ^= et[i];
        // deepenしないような遷移の後の値は計算済み
        if(deepen[i]) ans += memo[cumxor^x], memo[cumxor]++;
    }
    cout << ans << endl;
    return 0;
}