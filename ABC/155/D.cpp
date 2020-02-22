#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i];
    sort(v.begin(), v.end());
    auto f = [&](ll x)->int{
        return lower_bound(v.begin(),v.end(),x)-v.begin();
    };
    auto g = [&](ll x)->int{
        return upper_bound(v.begin(),v.end(),x)-v.begin();
    };
    ll l = -1e18-1, r = 1e18;
    while(r-l > 1){
        ll mid = (r+l)/2;
        ll tmp = 0;
        for(int i = 0; i < n; i++){
            if(mid <= 0){
                if(v[i] == 0){
                    tmp += (mid==0 ? n-i-1 : 0);
                }else if(v[i] > 0){
                    continue;
                }else if(v[i] < 0){
                    tmp += n-f((abs(mid)+abs(v[i])-1)/abs(v[i]));
                }
            }else if(mid > 0){
                if(v[i] == 0){
                    tmp += n-i-1;
                }else if(v[i] < 0){
                    tmp += n-f(0);
                    tmp += f(0)-max(i+1,f(-(mid/(-v[i]))));
                }else{
                    if(v[i]*v[i] > mid) continue;
                    tmp += g(mid/v[i])-(i+1);
                }
            }
        }
        if(tmp < k) l = mid;
        else        r = mid;
    }
    cout << r << endl;
    return 0;
}
