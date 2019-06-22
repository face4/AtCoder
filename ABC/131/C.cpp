#include<iostream>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a%b);
}

ll lcm(ll a, ll b){
    return a / gcd(a,b) * b;
}

int main(){
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll divc = b/c - (a+c-1)/c + 1;
    ll divd = b/d - (a+d-1)/d + 1;
    ll g = lcm(c,d);
    ll divcd = b/g - (a+g-1)/g + 1;
    cout << (b-a+1) - divc - divd + divcd << endl;
    return 0;
}