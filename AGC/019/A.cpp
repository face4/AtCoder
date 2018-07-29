#include<iostream>
using namespace std;

typedef long long ll;

int main(){
    ll q, h, s, d, n;
    cin >> q >> h >> s >> d >> n;

    ll sing = min(q*4, min(2*h, s));
    ll doub = min(q*8, min(4*h, min(2*s, d)));

    cout << n/2*doub + (n%2)*sing << endl;

    return 0;
}