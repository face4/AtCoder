#include<iostream>
using namespace std;

typedef long long ll;

int main(){
    ll a, b, x;
    cin >> a >> b >> x;
    if(a+b > x){
        cout << 0 << endl;
        return 0;
    }
    ll l = 1, r = 1e9+1;
    while(r-l > 1){
        ll mid = (l+r)/2;
        if(a*mid + b*(to_string(mid).length()) > x) r = mid;
        else                                        l = mid;
    }
    cout << l << endl;
    return 0;
}