#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// F : T x T -> T
// G : T x E -> T
// H : E x E -> E
// R : E x int(length of the range) -> E
template<typename T, typename E, typename F, typename G, typename H, typename R>
struct SegL{
private:
    vector<T> node;
    vector<E> lazy;
    int n;
    T defVal;
    E defOp;
    F f;    // merge elements(T)
    G g;    // update element(T) 
    H h;    // merge operators(E)
    R r;    // operator depends on length

    void init(int siz, T defVal, E defOp){
        n = 1;
        while(n < siz)  n *= 2;
        node.resize(2*n-1, defVal);
        lazy.resize(2*n-1, defOp);
    }

public:
    SegL(int siz, T defVal, E defOp, F f, G g, H h, R r) : defVal(defVal), defOp(defOp), f(f), g(g), h(h), r(r){
        init(siz, defVal, defOp);
    }
    SegL(vector<T> v, T defVal, E defOp, F f, G g, H h, R r) : defVal(defVal), defOp(defOp), f(f), g(g), h(h), r(r){
        init(v.size(), defVal, defOp);
        for(int i = 0; i < v.size(); i++)   node[n-1+i] = v[i];
        for(int i = n-2; i >= 0; i--)   node[i] = f(node[2*i+1], node[2*i+2]);
    }

    void eval(int k, int len){
        if(lazy[k] == defOp)    return;
        if(k < n-1){
            lazy[2*k+1] = h(lazy[2*k+1], lazy[k]);
            lazy[2*k+2] = h(lazy[2*k+2], lazy[k]);
        }
        node[k] = g(node[k], r(lazy[k], len));
        lazy[k] = defOp;
    }

    void update(int a, int b, E x, int k=0, int l=0, int r=-1){
        if(r < 0)   r = n;
        eval(k, r-l);
        if(b <= l || r <= a){
            return;
        }else if(a <= l && r <= b){
            lazy[k] = h(lazy[k], x);
            eval(k, r-l);
        }else{
            update(a, b, x, 2*k+1, l, (l+r)/2);
            update(a, b, x, 2*k+2, (l+r)/2, r);
            node[k] = f(node[2*k+1], node[2*k+2]);
        }
    }

    T query(int a, int b, int k=0, int l=0, int r=-1){
        if(r < 0)   r = n;
        eval(k, r-l);
        if(b <= l || r <= a)    return defVal;
        if(a <= l && r <= b)    return node[k];
        T lx = query(a, b, 2*k+1, l, (l+r)/2);
        T rx = query(a, b, 2*k+2, (l+r)/2, r);
        return f(lx, rx);
    }
};

typedef long long ll;

int main(){
    int n, q;
    cin >> n >> q;
    auto f = [](int a, int b){return min(a, b);};
    auto r = [](int a, int b){return a;};
    SegL<int, int, decltype(f), decltype(f), decltype(f), decltype(r)> seg1(n, n-1, n-1, f, f, f, r), seg2(n, n-1, n-1, f, f, f, r);
    ll ans = (ll)(n-2)*(n-2);
    while(q--){
        int a, b;
        cin >> a >> b;
        if(a == 1){
            int to = seg1.query(b-1, b);
            ans -= to-1;
            seg2.update(0, to+1, b-1);
        }else if(a == 2){
            int to = seg2.query(b-1, b);
            ans -= to-1;
            seg1.update(0, to+1, b-1);
        }
    }
    cout << ans << endl;
    return 0;
}