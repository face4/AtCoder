#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

struct STsum{
private:
    int n;
    vector<ll> dat;
public:
    STsum(int siz){
        n = 1;
        while(n < siz)   n *= 2;
        dat.resize(2*n-1, 0);
    }

    void update(int x, ll val){
        x += (n-1);
        dat[x] += val;
        while(x > 0){
            x = (x-1)/2;
            dat[x] = dat[2*x+1]+dat[2*x+2];
        }
    }
    
    // focus on k-th node, who controls [l, r)
    ll query(int a, int b, int k = 0, int l = 0, int r = -1){
        if(r < 0)   r = n;
        if(r <= a || b <= l)    return 0;
        if(a <= l && r <= b)    return dat[k];

        ll lx = query(a, b, 2*k+1, l, (l+r)/2);
        ll rx = query(a, b, 2*k+2, (l+r)/2, r);
        return lx+rx;
    }
};

struct BIT{
    vector<int> v;
    int n;

    BIT(int _n):
        v(vector<int>(_n+1, 0)), n(_n) {}

    int sum(int i){
        int s = 0;
        while(i > 0){
            s += v[i];
            i -= lsb(i);
        }
        return s;
    }
    
    int sum(int l, int r){
        return sum(r) - sum(l-1);
    }

    void add(int i, int x){
        while(i <= n){
            v[i] += x;
            i += lsb(i);
        }
    }

private:
    // least significant bit
    int lsb(int i){
        return i & -i;
    }
};



int main(){
    int q;
    cin >> q;
    vector<int> op(q), a(q), b(q), v;
    for(int i = 0; i < q; i++){
        cin >> op[i];
        if(op[i] == 1){
            cin >> a[i] >> b[i];
            v.push_back(a[i]);
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    auto f = [&](int val)->int{
        return lower_bound(v.begin(),v.end(),val)-v.begin();
    };
    int siz = v.size();
    BIT bit(siz);
    STsum seg(siz);

    ll bsum = 0;
    int num = 0; // number of updates
    for(int i = 0; i < q; i++){
        if(op[i] == 1){
            bsum += b[i];
            int pos = f(a[i]);
            bit.add(pos+1, 1);
            seg.update(pos, a[i]);
            num++;
        }else if(op[i] == 2){
            int l = 0, r = siz; // (l, r], 1-indexed
            while(r-l > 1){
                int mid = (l+r)/2;
                int tmp = bit.sum(mid);
                if(tmp >= (num+1)/2)  r = mid;
                else                l = mid;
            }
            int low = bit.sum(r-1), high = num-bit.sum(r);
            r--; // 0-indexed
            ll ans = 0;
            ans += (ll)low*v[r]-seg.query(0, r);
            ans += seg.query(r+1, siz+1)-(ll)high*v[r];
            ans += bsum;
            cout << v[r] << " " << ans << endl;
        }
    }
    return 0;
}