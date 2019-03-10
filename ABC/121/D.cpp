#include<iostream>
using namespace std;
typedef long long ll;

ll f(ll n, ll mod){
    if(n < 0)   return 0;
    ll ret = (n+1)/mod * (mod/2) +  max(0ll, n-((n+1)/mod*mod+mod/2)+1);
    return ret;
}

int main(){
    ll a, b;
    cin >> a >> b;
    ll ans =  0;
    for(int i = 0; i < 60; i++){
        if((1ll<<i) > b)  break;
        ll num = f(b, 1ll<<(i+1)) - f(a-1, 1ll<<(i+1));
        if(num%2)   ans += 1ll<<i;
    }
    cout << ans << endl;
    return 0;
}