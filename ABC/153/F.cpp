#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

class STlazy{
private:
    int n;
    vector<ll> node, lazy;

public:
    STlazy(vector<ll> v){
        int siz = v.size();
        n = 1;
        while(n < siz)  n *= 2;
        node.resize(2*n-1, 0);
        lazy.resize(2*n-1, 0);
        
        for(int i = 0; i < siz; i++)    node[n-1+i] = v[i];
        for(int i = n-2; i >= 0; i--)   node[i] = node[2*i+1] + node[2*i+2];
    }

    void eval(int k, int l, int r){
        if(lazy[k] == 0)    return;
        node[k] += lazy[k];
        if(r-l > 1){
            lazy[2*k+1] += lazy[k]/2;
            lazy[2*k+2] += lazy[k]/2;
        }
        lazy[k] = 0;
    }

    void add(int a, int b, ll x, int k=0, int l=0, int r=-1){
        if(r < 0)   r = n;
        eval(k, l, r);
        if(r <= a || b <= l)    return;
        if(a <= l && r <= b){
            lazy[k] += (r-l)*x;
            eval(k, l, r);
            return;
        }
        add(a, b, x, 2*k+1, l, (l+r)/2);
        add(a, b, x, 2*k+2, (l+r)/2, r);
        node[k] = node[2*k+1] + node[2*k+2]; // 自分の全ての子孫の値伝播が終わったら自分を更新する
    }

    ll query(int a, int b, int k=0, int l=0, int r=-1){
        if(r < 0)   r = n;
        if(r <= a || b <= l)    return 0;
        eval(k, l, r); // 最初の呼び出しが必ずeval(0,0,n)となるので漏れなく上から値の伝播がなされている
        if(a <= l && r <= b)    return node[k];
        ll lx = query(a, b, 2*k+1, l, (l+r)/2);
        ll rx = query(a, b, 2*k+2, (l+r)/2, r);
        return lx+rx;
    }
};

int main(){
    int n, d, a;
    cin >> n >> d >> a;
    vector<pii> vp;
    for(int i = 0; i < n; i++){
        int x, h;
        cin >> x >> h;
        vp.push_back({x, h});
    }
    sort(vp.begin(), vp.end());
    
    vector<ll> za;
    for(int i = 0; i < n; i++)  za.push_back(vp[i].first);

    vector<ll> emp(n, 0);
    STlazy seg(emp);
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ll hist = seg.query(i, i+1);
        ll hp = vp[i].second;
        if(hist*a >= hp)  continue;
        ll attack = (hp-hist*a+a-1)/a;
        ans += attack;
        ll from = vp[i].first;
        ll to = from+2*d;
        int x = --upper_bound(za.begin(),za.end(),to)-za.begin();
        seg.add(i, x+1, attack);
    }
    cout << ans << endl;
    return 0;
}