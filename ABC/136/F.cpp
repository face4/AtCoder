#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct BIT{
    int n;
    vector<int> v;

    BIT(int _n) : n(_n){
        v.resize(n+1, 0);
    }

    void add(int i, int x){
        while(i <= n){
            v[i] += x;
            i += i&-i;
        }
    }

    int sum(int i){
        int ret = 0;
        while(i > 0){
            ret += v[i];
            i -= i&-i;
        }
        return ret;
    }
};

typedef pair<int,int> pii;
typedef long long ll;
const int mod = 998244353;

int main(){
    int n;
    cin >> n;
    vector<pii> vp;
    vector<int> y;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        vp.push_back({a,b});
        y.push_back(b);
    }
    sort(y.begin(), y.end());
    BIT bit(n);
    for(int i = 1; i <= n; i++) bit.add(i, 1);
    sort(vp.begin(), vp.end());
    vector<ll> fact(n+1, 1);
    for(int i = 1; i <= n; i++) fact[i] = fact[i-1]*2%mod;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        int down = lower_bound(y.begin(),y.end(),vp[i].second)-y.begin();
        int up = n-1-down;
        bit.add(down+1, -1);
        
        // select vp[i]
        (ans += fact[n-1]) %= mod;   
        
        int s[4];
        s[3] = bit.sum(down+1);
        s[1] = bit.sum(n)-bit.sum(down+1);
        s[2] = down-s[3];
        s[0] = up-s[1];
        bool all = true;
        ll alladd = 1;
        for(int x = 0; x < 4; x++){
            all &= s[x]>0;
            (alladd *= fact[s[x]]-1) %= mod;
            if(x < 2 && s[x] > 0 && s[3-x] > 0){
                (ans += (fact[s[x]]-1)*(fact[s[3-x]]-1)%mod) %= mod;
            }
            bool ok = true;
            ll tmp = 1;
            for(int y = 0; y < 4; y++){
                if(x != y)  ok &= s[y]>0, (tmp *= fact[s[y]]-1) %= mod;
            }
            if(ok)  (ans += tmp) %= mod;
        }
        if(all) (ans += alladd) %= mod;
    }
    cout << ans << endl;
    return 0;
}
