#include<iostream>
#include<vector>
#include<set>
using namespace std;
typedef unsigned long long ll;

const ll mod = 1e9 + 7;

int main(){
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i];
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ll cnt = 0;
        for(int j = i+1; j < n; j++){
            if(v[i] > v[j]) cnt++;
        }
        ll tmp = 0;
        for(int j = 0; j < n; j++){
            if(v[i] > v[j]) tmp++;
        }
        ans += ((2*cnt+(k-1)*tmp)%mod*k/2)%mod;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}