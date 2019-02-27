#include<iostream>
#include<vector>
using namespace std;

const int INF = 1<<30;
// O(n^3)
int main(){
    int n, m;
    cin >> n >> m;
    int a, b, t;
    vector<vector<int>> v(n, vector<int>(n, INF));
    for(int i = 0; i < n; i++)  v[i][i] = 0;
    while(m-- > 0){
        cin >> a >> b >> t;
        a--, b--;
        v[a][b] = v[b][a] = t;
    }
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(v[i][k] == INF || v[k][j] == INF)    continue;
                v[i][j] = min(v[i][j], v[i][k]+v[k][j]);
            }
        }
    }
    int ans = INF;
    for(int k = 0; k < n; k++){
        int tmp = 0;
        for(int i = 0; i < n; i++){
            tmp = max(tmp, v[i][k]);
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}