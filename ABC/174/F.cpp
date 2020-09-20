#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

struct BIT{
    // 1-origin
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

    ll invNum(){
        ll ret = 0;
        for(int j = 0; j < n; j++){
            ret += j - sum(v[j]);
            add(v[j], 1);
        }
        return ret;
    }

private:
    // least significant bit
    int lsb(int i){
        return i & -i;
    }
};

typedef pair<int,int> pii;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    int c[n];
    for(int i = 0; i < n; i++)  cin >> c[i], c[i]--;
    vector<pair<pii,int>> vp;
    for(int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        vp.push_back({{--r, --l}, i});
    }
    sort(vp.begin(), vp.end());
    vector<int> last(n, -1), ans(q);
    int qind = 0;
    BIT bit(n);
    for(int i = 0; i < n; i++){
        if(last[c[i]] != -1){
            bit.add(last[c[i]]+1, -1);
        }
        last[c[i]] = i;
        bit.add(last[c[i]]+1, 1);
        while(qind < q && vp[qind].first.first == i){
            ans[vp[qind].second] = bit.sum(i+1)-bit.sum(vp[qind].first.second);
            qind++;
        }
    }
    for(int i = 0; i < q; i++)  cout << ans[i] << endl;
    return 0;
}

