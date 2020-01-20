#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<climits>
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
        node[x] = f(node[x], val); /* ! */
        while(x){
            x = (x-1)/2;
            node[x] = f(node[2*x+1], node[2*x+2]);
        }
    }

    T query(int a, int b){
        int L = a+n-1, R = b+n-1;
        T ret = def;
        while(L < R){
            if((R&1) == 0)  ret = f(ret, node[--R]);
            if((L&1) == 0)  ret = f(ret, node[L++]);
            L >>= 1, R >>= 1;
        }
        return ret;
    }
};

typedef pair<int,int> pii;

int main(){
    int n;
    cin >> n;
    vector<int> v;
    vector<pii> vp;
    for(int i = 0; i < n; i++){
        int x, l;
        cin >> x >> l;
        vp.push_back({x-l, x+l});
        v.push_back(x-l);
        v.push_back(x+l);
    }
    v.push_back(-2e9-1);
    v.push_back(2e9+1);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    auto f = [&](int x)->int{
        return lower_bound(v.begin(),v.end(),x)-v.begin();
    };
    Seg<int> seg(v.size(), 0, [](int x, int y){return max(x,y);});
    sort(vp.begin(), vp.end());
    for(int i = 0; i < n; i++){
        seg.update(f(vp[i].second), seg.query(0, f(vp[i].first)+1)+1);
    }
    cout << seg.query(0, v.size()) << endl;
    return 0;
}