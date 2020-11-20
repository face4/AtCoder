#include<iostream>
using namespace std;
typedef long long ll;

ll f(ll x){
    return x*(x+1)/2;
}

int main(){
    int n;
    cin >> n;
    ll ans = 0;
    while(n--){
        ll a, b;
        cin >> a >> b;
        ans += f(b) - f(a-1);
    }
    cout << ans << endl;
    return 0;
}