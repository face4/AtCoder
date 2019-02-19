#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    ll k, a, b;
    cin >> k >> a >> b;

    ll ans = 0;
    ll first = a - 1 + 1 + 1; // hit a-1 times, exchange , exchange
    if(2 >= b - a || first > k){
        cout << k+1 << endl;
        return 0;
    }

    k -= first;
    ans += b;

    ll rep = k / 2;
    ans += (b-a) * rep;
    ans += k % 2;

    cout << ans << endl;
    return 0;
}