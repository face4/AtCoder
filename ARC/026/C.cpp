#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

typedef long long ll;
const ll INF = 1ll<<50;

struct STmin{
private:
    int n;
    vector<ll> dat;
public:
    STmin(vector<ll> ini){
        int siz = ini.size();
        n = 1;
        while(n < siz)   n *= 2;
        dat.resize(2*n-1, INF);
        for(int i = 0; i < siz; i++)    dat[n - 1 + i] = ini[i];
        for(int i = n-2; i >= 0; i--)   dat[i] = min(dat[2*i+1], dat[2*i+2]);
    }

    void assign(int x, ll val){
        x += (n-1);
        if(val > dat[x])    return;
        dat[x] = val;
        while(x > 0){
            x = (x-1)/2;
            dat[x] = min(dat[2*x+1], dat[2*x+2]);
        }
    }

    // focus on k-th node, who controls [l, r)
    ll query(int a, int b, int k = 0, int l = 0, int r = -1){
        if(r < 0)   r = n;
        if(r <= a || b <= l)    return INF;
        if(a <= l && r <= b)    return dat[k];

        ll lx = query(a, b, 2*k+1, l, (l+r)/2);
        ll rx = query(a, b, 2*k+2, (l+r)/2, r);
        return min(lx, rx);
    }
};

struct light{
    int l, r, c;
    bool operator<(const light other) const{
        return r < other.r;
    }
};

int main(){
    int n, l;
    cin >> n >> l;
    vector<ll> dp(l+1, INF);
    dp[0] = 0;
    vector<light> v;
    int a, b, c;
    for(int i = 0; i < n; i++){
        cin >> a >> b >> c;
        v.push_back(light({a, b, c}));
    }
    sort(v.begin(), v.end());
    STmin st(dp);
    for(int i = 0; i < n; i++){
        ll tmp = st.query(v[i].l, v[i].r) + v[i].c;
        if(tmp < dp[v[i].r]){
            dp[v[i].r] = tmp;
            st.assign(v[i].r, tmp);
        }
    }
    cout << dp[l] << endl;
    return 0;
}