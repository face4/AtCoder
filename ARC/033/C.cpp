#include<iostream>
#include<vector>
using namespace std;

struct BIT{
    vector<int> v;
    int n;
    BIT(int siz){
        n = siz;
        v.resize(n+1, 0);
    }
    void add(int x, int val){
        while(x <= n){
            v[x] += val;
            x += x&-x;
        }
    }
    int query(int x){
        int ret = 0;
        while(x > 0){
            ret += v[x];
            x -= x&-x;
        }
        return ret;
    }
};

int main(){
    int q, t, x;
    cin >> q;
    BIT bit(200000);
    while(q-- > 0){
        cin >> t >> x;
        if(t == 1){
            bit.add(x, 1);
        }else if(t == 2){
            int l = 0, r = 200000;
            while(r-l > 1){
                int mid = (l+r)/2;
                int sum = bit.query(mid);
                if(sum < x)    l = mid;
                else           r = mid;
            }
            cout << r << endl;
            bit.add(r, -1);
        }
    }
    return 0;
}