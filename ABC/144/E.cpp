#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
typedef long long ll;

int main(){
    int n;
    ll k;
    cin >> n >> k;
    vector<int> a(n), f(n);
    for(int i = 0; i < n; i++)  cin >> a[i];
    for(int i = 0; i < n; i++)  cin >> f[i];
    if(accumulate(a.begin(), a.end(), 0ll) <= k){
        cout << 0 << endl;
        return 0;
    }
    sort(a.begin(), a.end());
    sort(f.rbegin(), f.rend());
    ll l = 0, r = 1ll<<60;
    while(r-l > 1){
        ll mid = (l+r)/2;
        ll tmp = 0;
        for(int i = 0; i < n; i++){
            tmp += max(0ll, (ll)a[i]-(mid/f[i]));
        }
        if(tmp > k) l = mid;
        else        r = mid;
    }
    cout << r << endl;
    return 0;
}