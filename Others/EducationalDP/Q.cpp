// 自力AC
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

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
        node[x] = f(node[x],val); /* ! */
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

typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> h(n), a(n);
    for(int i = 0; i < n; i++)  cin >> h[i];
    for(int i = 0; i < n; i++)  cin >> a[i];
    vector<int> z = h;
    // z.push_back(0); z.push_back(1<<30);
    sort(z.begin(), z.end());
    z.erase(unique(z.begin(),z.end()),z.end());
    int siz = z.size();
    auto f = [&](int val)->int{
        return lower_bound(z.begin(),z.end(),val)-z.begin();
    };
    Seg<ll> seg(siz, 0, [](ll x, ll y){return max(x,y);});
    for(int i = 0; i < n; i++){
        seg.update(f(h[i]), seg.query(0, f(h[i]))+a[i]);
    }
    cout << seg.query(0, siz+1) << endl;
    return 0;
}
