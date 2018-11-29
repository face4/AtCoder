#include<iostream>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a%b);
}

int main(){
    ll x, y;
    scanf("%lld/%lld", &x, &y);

    ll g = gcd(x, y);
    x /= g, y /= g;

    ll k = (4*x-2*y)/y/y;
    if(k*k*y*y+2*k*y-4*k*x < 0) k++;

    bool imp = true;
    for(;k*k*y*y-2*k*y-4*k*x <= 0;k++){
        if( (k*y)%2 == 0 && (k*k*y*y+2*k*y-4*k*x)%8 == 0 ){
            ll n = (k*y)/2, m = (k*k*y*y+2*k*y-4*k*x)/8;
            if(n == 0 || m == 0)    continue;
            imp = false;
            cout << n << " " << m << endl;
        }
    }

    if(imp) cout << "Impossible" << endl;
    
    return 0;
}