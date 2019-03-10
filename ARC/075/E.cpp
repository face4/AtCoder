#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

const int INF = 1<<30;
struct ST{
private:
    int n;
    vector<int> node;
public:
    ST(int siz){
        n = 1;
        while(n < siz)   n *= 2;
        node.resize(2*n-1, 0);
    }

    void update(int x, int val){
        x += (n-1);
        node[x] += val;
        while(x > 0){
            x = (x-1)/2;
            node[x] = node[2*x+1] + node[2*x+2];
        }
    }

    // focus on k-th node, who controls [l, r)
    int query(int a, int b, int k = 0, int l = 0, int r = -1){
        if(r < 0)   r = n;
        if(r <= a || b <= l)    return 0;
        if(a <= l && r <= b)    return node[k];

        int lx = query(a, b, 2*k+1, l, (l+r)/2);
        int rx = query(a, b, 2*k+2, (l+r)/2, r);
        return lx + rx;
    }
};

int main(){
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i], v[i]-=k;
    vector<ll> x;
    ll sum = 0;
    for(int i = 0; i < n; i++){
        sum += v[i];
        x.push_back(sum);
    }
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    auto pos = [&](ll val)->int{
        return lower_bound(x.begin(), x.end(), val)-x.begin();
    };
    ST segment(x.size());
    sum = 0;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        sum += v[i];
        ans += segment.query(0, pos(sum)+1);
        segment.update(pos(sum), 1);
        if(sum >= 0) ans++;
    }
    cout << ans << endl;
    return 0;
}