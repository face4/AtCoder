// 自力AC
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n, p;
    cin >> n >> p;
    vector<pair<int,int>> vp;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        vp.push_back({a, b});
    }
    sort(vp.rbegin(), vp.rend());
    int ans = 0;
    vector<int> dp(p+101, 0);
    for(int i = 0; i < n; i++){
        int w = vp[i].first;
        int v = vp[i].second;
        for(int j = p+100-w; j >= 0; j--){
            dp[j+w] = max(dp[j+w], dp[j]+v);
        }
        ans = max(ans, dp[p+w]);
    }
    cout << ans << endl;
}
