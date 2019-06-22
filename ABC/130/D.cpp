#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

int main(){
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i];
    ll ans = 0, sum = 0;
    int l = 0, r = 0;
    while(l < n){
        while(r < n && sum < k) sum += v[r++];
        if(sum < k) break;
        ans += n-r+1;
        sum -= v[l++];
    }
    cout << ans << endl;
    return 0;
}