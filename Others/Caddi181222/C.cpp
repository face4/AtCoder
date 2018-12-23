#include<iostream>
#include<map>
using namespace std;
typedef long long ll;

int main(){
    ll n, p;
    cin >> n >> p;

    map<ll,ll> cnt;
    for(ll i = 2; i*i <= p; i++){
        while(p%i == 0) p /= i, cnt[i]++;
    }
    if(p != 1)  cnt[p]++;

    ll ans = 1;
    for(auto p : cnt){
        if(p.second >= n){
            ll times = p.second/n;
            while(times-- > 0)  ans *= p.first;
        }
    }

    cout << ans << endl;

    return 0;
}