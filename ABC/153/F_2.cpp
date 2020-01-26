#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

typedef long long ll;

int main(){
    int n, d, a;
    cin >> n >> d >> a;
    vector<pair<int,int>> vp;
    for(int i = 0; i < n; i++){
        int x, h;
        cin >> x >> h;
        vp.push_back({x, h});
    }
    sort(vp.begin(), vp.end());
    queue<pair<ll,ll>> q;
    ll ans = 0, acc = 0;
    for(int i = 0; i < n; i++){
        while(!q.empty() && vp[i].first > q.front().first){
            acc -= q.front().second;
            q.pop();
        }
        ll res = vp[i].second-acc*a;
        if(res <= 0)    continue;
        ll need = (res+a-1)/a;
        ans += need;
        q.push({vp[i].first+2*d, need});
        acc += need;
    }
    cout << ans << endl;
}