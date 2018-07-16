#include<iostream>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b){
    return (b == 0) ? a : gcd(b, a%b);
}

ll lcm(ll a, ll b){
    return a/gcd(a,b)*b;
}

int main(){
    int n;
    cin >> n;

    ll ans = 1;
    ll t;
    
    for(int i = 0; i < n; i++){
        cin >> t;
        ans = lcm(ans,t);
    }

    cout << ans << endl;
    
    return 0;
}