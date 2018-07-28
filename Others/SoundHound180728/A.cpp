#include<iostream>
using namespace std;

typedef long long ll;

int main(){
    ll c, d;
    cin >> c >> d;

    ll ans = 0;

    ll from, to;
    ll beki = 1;

    while(beki * 170 < c){
        beki *= 2;
    }

    from = 140 * beki;
    to = 170 * beki;

    while(from < d){
        if(to <= d){
            ans += to - max(from, c); 
        }else{
            ans += d - max(from, c);
        }

        from *= 2ll;
        to *= 2ll;
    }

    cout << ans << endl;

    return 0;
}
