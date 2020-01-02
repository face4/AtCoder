#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
typedef long long ll;

template<typename T>
struct Seg{
private:
    vector<T> node;
    int n;
    function<T(T,T)> f;
    T def;

public:
    Seg(int siz, T d, function<T(T,T)> f) : def(d), f(f) {
        n = 1;
        while(n < siz)  n *= 2;
        node.resize(2*n-1, def);
    }
    Seg(vector<T> v, T d, function<T(T,T)> f) : def(d), f(f){
        n = 1;
        while(n < v.size())  n *= 2;
        node.resize(2*n-1);
        for(int i = 0; i < v.size(); i++)   node[n-1+i] = v[i];
        for(int i = n-2; i >= 0; i--)   node[i] = f(node[2*i+1], node[2*i+2]);
    }

    void update(int x, T val){
        x += n-1;
        node[x] = val; /* ! */
        while(x){
            x = (x-1)/2;
            node[x] = f(node[2*x+1], node[2*x+2]);
        }
    }

    T query(int a, int b, int k=0, int l=0, int r=-1){
        if(r < 0)   r = n;
        if(b <= l || r <= a)    return def;
        if(a <= l && r <= b)    return node[k];
        T lx = query(a, b, 2*k+1, l, (l+r)/2);
        T rx = query(a, b, 2*k+2, (l+r)/2, r);
        return f(lx, rx);
    }
};

int main(){
    int n, v, p;
    ll m;
    cin >> n >> m >> v >> p;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)  cin >> a[i];
    sort(a.begin(), a.end());
    Seg<ll> seg(a, 0ll, [](ll x, ll y){return x+y;});
    ll target = a[n-p];
    int l = -1, r = n-1;
    while(r-l > 1){
        int mid = (l+r)/2;
        // 元々上からp番目以内に入っている
        if(n-mid <= p){
            r = mid;
            continue;
        }
        if(a[mid]+m < target){
            l = mid;
            continue;
        }
        ll afford = m*(lower_bound(a.begin(),a.end(),a[mid])-a.begin());
        afford += (p-1)*m;
        int x = lower_bound(a.begin(),a.end(),a[mid])-a.begin();
        afford += (ll)(n-p-x+1-1)*(a[mid]+m)-seg.query(x, n-p+1)+a[mid];
        if(afford >= m*(v-1))   r = mid;
        else                    l = mid;
    }
    cout << n-r << endl;
    return 0;
}