#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

int main(){
    int n, k;
    cin >> n >> k;

    ll a[n+1];
    a[0] = 0;
    for(int i = 1; i <= n; i++)  cin >> a[i], a[i] += a[i-1];

    vector<ll> v;
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            v.push_back(a[j]-a[i-1]);
        }
    }

    sort(v.begin(), v.end());

    int i;
    for(i = 62; i >= 0; i--){
        ll tmp = 1ll<<i;
        int cnt = 0;
        for(ll val : v) if((val&tmp) > 0) cnt++;
        if(cnt >= k)    break;
    }

    if(i == -1){
        cout << 0 << endl;
        return 0;
    }

    //ll ans = 1ll<<i;

    vector<ll> c;
    for(ll val : v) if((val&(1ll<<i)) > 0)    c.push_back(val);

    i--;
    while(i >= 0 && c.size() > k){
        vector<ll> next;
        ll tmp = 1ll<<i;
        for(ll val : c) if((val&tmp) > 0) next.push_back(val);
        if(next.size() >= k){
            c = next;
            //ans |= (1ll<<i);
        }
        i--;
    }

    ll ans = c[0];
    for(int i = 1; i < c.size(); i++)   ans &= c[i];
    
    cout << ans << endl;

    return 0;
}