#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    int n;
    scanf("%d", &n);

    vector<ll> h(n), s(n);
    for(int i = 0; i < n; i++)  scanf("%lld %lld", h.begin()+i, s.begin()+i);

    auto f = [=](ll mid) -> bool{
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            if(mid < h[i])  return false;
            ll need = (mid-h[i])/s[i];
            if(need < n)    v[need]++;
        }
        int acc = 0;
        for(int i = 0; i < n; i++){
            acc += v[i];
            if(acc > i+1)   return false;
        }
        return true;
    };

    ll l = 1, r = 1e18+5;
    while(r-l > 1){
        ll mid = (l+r)/2;
        if(f(mid))  r = mid;
        else        l = mid;
    }

    cout << r << endl;

    return 0;
}