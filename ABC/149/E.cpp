#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    int n;
    ll m;
    cin >> n >> m;
    vector<int> cnt(200001, 0), v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        cnt[v[i]]++;
    }
    vector<int> sum = cnt;
    for(int i = 100000-1; i >= 0; i--)  sum[i] += sum[i+1];
    auto f = [&](int mid)->ll{
        ll ret = 0;
        for(int i = 100000; i >= 0; i--)    ret += (ll)cnt[i]*sum[max(mid-i,0)];
        return ret;
    };
    int l = 0, r = 200001;
    while(r-l > 1){
        int mid = (l+r)/2;
        if(f(mid) < m)  r = mid;
        else            l = mid;
    }
    vector<ll> cum(200001, 0);
    for(int i = 100000; i >= 0; i--)    cum[i] = cum[i+1]+(ll)i*cnt[i];
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans += (ll)v[i]*sum[max(0,l-v[i])] + cum[max(0,l-v[i])];
    }
    ans -= l*(f(l)-m);
    cout << ans << endl;
    return 0;
}