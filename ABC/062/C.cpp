#include<iostream>
#include<climits>
using namespace std;

typedef long long ll;

int main(){
    ll h, w;
    cin >> h >> w;

    ll w2 = w/2, h2 = h/2;
    ll ans = 1ll<<55;
    for(ll i = 1; i < h; i++){
        ll a = i*w;
        ll b = (h-i)*w2;
        ll c = (h-i)*(w-w2);
        ans = min(ans, max(a,max(b,c))-min(a,min(b,c)));
    }
    for(ll i = 1; i < w; i++){
        ll a = i*h;
        ll b = (w-i)*h2;
        ll c = (w-i)*(h-h2);
        ans = min(ans, max(a,max(b,c))-min(a,min(b,c)));
    }
    
    if(h%3 == 0 || w%3 == 0)    ans = 0;
    if(h >= 3)  ans = min(ans, w);
    if(w >= 3)  ans = min(ans, h);
    cout << ans << endl;

    return 0;
}