#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    int n, m;
    cin >> n >> m;
    vector<ll> h(n), w(m);
    for(int i = 0; i < n; i++)  cin >> h[i];
    sort(h.begin(), h.end());
    for(int i = 0; i < m; i++)  cin >> w[i];
    if(n == 1){
        ll ans = 1ll<<60;
        for(int i = 0; i < m; i++)  ans = min(ans, abs(w[i]-h[0]));
        cout << ans << endl;
        return 0;
    }
    vector<ll> bef(n,0), aft(n,0);
    for(int i = 1; i < n; i++)       bef[i] = (i==1?0:bef[i-2])+h[i]-h[i-1];
    for(int i = n-2; i >= 0; i--)    aft[i] = (i+2<n?aft[i+2]:0)+h[i+1]-h[i];
    ll ans = 1ll<<60;
    for(int i = 0; i < m; i++){
        int le = lower_bound(h.begin(), h.end(), w[i])-h.begin();
        if(le == n){
            ans = min(ans, bef[n-2]+w[i]-h[n-1]);
        }else if(le == 0){
            ans = min(ans, aft[1]+h[0]-w[i]);
        }else if(le%2 == 1){
            ans = min(ans, (le-2>=0?bef[le-2]:0)+w[i]-h[le-1]+aft[le]);
        }else{
            ans = min(ans, bef[le-1]+h[le]-w[i]+(le+1<n?aft[le+1]:0));
        }
    }
    cout << ans << endl;
    return 0;
}