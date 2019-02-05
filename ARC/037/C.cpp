#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    int n, k;
    cin >> n >> k;

    vector<ll> a(n), b(n);
    for(int i = 0; i < n; i++)  cin >> a[i];
    for(int i = 0; i < n; i++)  cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll l = 1, r = 1e18+1;
    while(r-l > 1){
        ll mid = (l+r)/2;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            cnt += upper_bound(b.begin(), b.end(), mid/a[i]) - b.begin();
        }
        if(cnt >= k){
            r = mid;
        }else{
            l = mid;
        }
    }

    cout << r << endl;

    return 0;
}