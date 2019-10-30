#include<iostream>
#include<vector>
#include<iomanip>
#include<set>
using namespace std;

bool ok[600][600] = {};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<int> v[n], way(n);
    vector<pair<int,int>> vp;
    for(int i = 0; i < m; i++){
        int s, t;
        cin >> s >> t;
        vp.push_back({--s, --t});
        way[s]++;
        v[s].push_back(t);
        ok[s][t] = true;
    }
    vp.push_back({n-1,n-1});    // do nothing.
    double ans = 100000;
    vector<double> pr(n, 0), dp(n, 0);
    for(int i = m; i < m+1; i++){
        ok[vp[i].first][vp[i].second] = false;
        pr[0] = 1;
        bool flag = false;
        for(int pos = 0; pos+1 < n; pos++){
            if(pr[pos] == 0)    continue;
            int way = 0;
            for(int j : v[pos]) if(ok[pos][j])  way++;
            if(way == 0){
                if(pr[pos] > 0) flag = true;
                continue;
            }    
            for(int j : v[pos]){
                if(ok[pos][j]){
                    dp[j] += dp[pos]/way + pr[pos]/way;
                    pr[j] += pr[pos]/way;
                }  
            } 
        }
        if(!flag)  ans = min(ans, dp.back());
        ok[vp[i].first][vp[i].second] = true;
    }

    for(int i = 0; i < m; i++){
        if(pr[vp[i].first] > 0 && way[vp[i].first] == 1)    continue;
        ok[vp[i].first][vp[i].second] = false;
        way[vp[i].first]--;
        vector<double> ndp = dp;
        vector<double> npr = pr;
        for(int pos = vp[i].first; pos+1 < n; pos++){
            if(npr[pos] == 0)    continue;
            for(int j : v[pos]){
                if(ok[pos][j]){
                    ndp[j] += (ndp[pos]+npr[pos])/way[pos]-(ndp[pos]+npr[pos])/(way[pos]+1);
                    npr[j] += npr[pos]/way[pos]-npr[pos]/(way[pos]+1);
                }else{
                    ndp[j] -= (ndp[pos]+npr[pos])/(way[pos]+1);
                    npr[j] -= npr[pos]/(way[pos]+1);
                }
            } 
        }
        ans = min(ans, ndp.back());
        ok[vp[i].first][vp[i].second] = true;
        way[vp[i].first]++;
    }
    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}