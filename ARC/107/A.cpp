#include<iostream>
using namespace std;

typedef long long ll;
const ll mod = 998244353;

ll f(ll x){
    return x*(x+1)/2%mod;
}

int main(){
    ll a, b, c;
    cin >> a >> b >> c;
    cout << f(a)*f(b)%mod*f(c)%mod << endl;
    return 0;
}