#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;
const ll INF = 1ll<<60;

vector<int> v, w;
int n, W;

ll half(){
    int n1 = n/2;
    vector<pair<ll,ll>> vp;
    for(int i = 0; i < 1<<n1; i++){
        ll tmpw = 0, tmpv = 0;
        for(int j = 0; j < n1; j++){
            if((i>>j)&1)    tmpw += w[j], tmpv += v[j];
        }
        vp.push_back({tmpw, tmpv});
    }
    sort(vp.begin(), vp.end());
    int cur = 1;
    for(int i = 1; i < vp.size(); i++){
        if(vp[i].second > vp[cur-1].second){
            vp[cur++] = vp[i];
        }
    }
    ll ret = 0;
    for(int i = 0; i < 1<<(n-n1); i++){
        ll tmpw = 0, tmpv = 0;
        for(int j = 0; j < (n-n1); j++){
            if((i>>j)&1)    tmpw += w[n1+j], tmpv += v[n1+j];
        }
        if(tmpw > W)    continue;
        pair<ll,ll> tmp = make_pair(W-tmpw, INF);
        auto it = upper_bound(vp.begin(), vp.begin()+cur, tmp);
        it--;
        if(tmpw + (*it).first <= W)   ret = max(ret, (*it).second + tmpv);
    }
    return ret;
}

ll val(){
    vector<ll> dp(200001, INF);
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 200000-v[i]; j >= 0; j--){
            if(dp[j] == INF)    continue;
            dp[j+v[i]] = min(dp[j+v[i]], dp[j]+w[i]);
        }
    }
    for(int i = 200000; i >= 0; i--){
        if(dp[i] <= W)  return i;
    }
    return -1;
}

ll wei(){
    vector<ll> dp(200001, 0);
    for(int i = 0; i < n; i++){
        for(int j = 200000-w[i]; j >= 0; j--){
            dp[j+w[i]] = max(dp[j+w[i]], dp[j]+v[i]);
        }
    }
    ll ret = 0;
    for(int i = min(200000, W); i >= 0; i--){
        ret = max(ret, dp[i]);
    }
    return ret;
}

int main(){
    cin >> n >> W;

    bool vlim = true;
    v.resize(n), w.resize(n);
    for(int i = 0; i < n; i++){
        cin >> v[i] >> w[i];
        vlim &= (v[i] <= 1000);
    }

    ll ans = 0;
    if(n <= 30)     ans = half();
    else if(vlim)   ans = val();
    else            ans = wei();

    cout << ans << endl;

    return 0;
}
