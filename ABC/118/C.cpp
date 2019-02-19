#include<iostream>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a%b);
}

int main(){
    int n;
    cin >> n;

    ll x;
    cin >> x;

    for(int i = 1; i < n; i++){
        ll a;
        cin >> a;
        x = gcd(x, a);
    }

    cout << x << endl;

    return 0;
}