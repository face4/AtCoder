#include<iostream>
using namespace std;

typedef long long ll;

int main(){
    ll n;
    cin >> n;
    ll ans = 0;
    for(ll a = 1; a < n; a++){
        ans += (n-1)/a;
    }
    cout << ans << endl;
    return 0;
}