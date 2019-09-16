// 解説を読んだ
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<ll> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i];
    vector<ll> sum(n+1);
    sum[0] = 0;
    for(int i = 0; i < n; i++)  sum[i+1] = sum[i] + v[i];
    auto f = [&](int l, int r)->ll{
        return sum[r] - sum[l-1];
    };
    ll ans = 1ll<<60;
    int le = 1, ri = 3;
    for(int center = 2; center <= n-2; center++){
        ll diff = abs(f(1, le)-f(le+1, center));
        while(true){
            ll tmp = abs(f(1,le+1)-f(le+2, center));
            if(diff > tmp){
                diff = tmp;
                le++;
            }else{
                break;
            }
        }
        diff = abs(f(center+1, ri)-f(ri+1, n));
        while(true){
            ll tmp = abs(f(center+1, ri+1)-f(ri+2, n));
            if(diff > tmp){
                diff = tmp;
                ri++;
            }else{
                break;
            }
        }
        ll a = f(1, le), b = f(le+1, center), c = f(center+1, ri), d = f(ri+1, n);
        ans = min(ans, max({a,b,c,d})-min({a,b,c,d}));
    }
    cout << ans << endl;
    return 0;
}