#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i];
    ll sum = accumulate(v.begin(), v.end(), 0ll)%mod;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        sum += mod-v[i];
        sum %= mod;
        ans += sum*v[i]%mod;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}