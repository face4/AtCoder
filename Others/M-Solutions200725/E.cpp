#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

vector<int> x, y, p;
vector<vector<int>> a, b;
vector<ll> ans;
int n;

int bitx = 0, bity = 0, pop = 0;

void dfs(int ind){
    if(ind == n){
        ll tmp = 0;
        for(int i = 0; i < n; i++){
            int diff = min({abs(x[i]), abs(y[i]), a[i][bitx], b[i][bity]});
            tmp += (ll)diff * p[i];
        }
        ans[pop] = min(ans[pop], tmp);
        return;
    }
    bitx ^= 1<<ind; pop++;
    dfs(ind+1);
    bitx ^= 1<<ind; 
    bity ^= 1<<ind;
    dfs(ind+1);
    bity ^= 1<<ind; pop--;
    dfs(ind+1);
}

int main(){
    cin >> n;
    x.resize(n);
    y.resize(n);
    p.resize(n);
    ans.resize(n+1, 1ll<<60);
    a.resize(n, vector<int>(1<<n, 30000));
    b.resize(n, vector<int>(1<<n, 30000));
    for(int i = 0; i < n; i++)  cin >> x[i] >> y[i] >> p[i];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 1<<n; j++){
            for(int k = 0; k < n; k++){
                if(j>>k&1)  a[i][j] = min(a[i][j], abs(x[k]-x[i])), b[i][j] = min(b[i][j], abs(y[k]-y[i]));
            }
        }
    }
    dfs(0);
    for(int i = 0; i < n+1; i++)  cout << ans[i] << endl;
    return 0;
}