#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

int main(){
    int n, t;
    cin >> n >> t;
    vector<pair<ll,ll>> vp;
    for(int i = 0; i < n; i++){
        ll a, b;
        cin >> a >> b;
        vp.push_back({a,b});
    }
    sort(vp.begin(), vp.end(), [](pll x, pll y){
        return x.second*y.first+y.second >= x.first*y.second+x.first+x.second;
    });
    ll now = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        ll a = vp[i].first, b = vp[i].second;
        if(now+1+a*(now+1)+b > t) break;
        ans++;
        now += 1+a*(now+1)+b;
    }
    cout << ans << endl;
    return 0;
}