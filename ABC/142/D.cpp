#include<iostream>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a%b);
}

int main(){
    ll a, b;
    cin >> a >> b;
    ll g = gcd(a, b);
    ll ans = 1;
    for(ll i = 2; i*i <= g; i++){
        if(g%i) continue;
        ans++;
        while(g%i == 0) g /= i;
    }
    if(g != 1)    ans++;
    cout << ans << endl;
    return 0;
}