#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool comp(pair<int,int> a, pair<int,int> b){
    if(a.first != b.first)  return a.first < b.first;
    else                    return a.second > b.second;
}

struct ST{
private:
    int n;
    vector<int> node;
public:
    ST(int s){
        n = 1;
        while(n < s)    n *= 2;
        node.resize(2*n-1, 0);
    }

    void assign(int i, int x){
        i += n-1;
        if(node[i] >= x)    return;
        node[i] = x;
        while(i > 0){
            i = (i-1)/2;
            node[i] = max(node[2*i+1], node[2*i+2]);
        }
    }

    int query(int a, int b, int k=0, int l=0, int r=-1){
        if(r < 0)   r = n;
        if(r <= a || b <= l)    return 0;
        if(a <= l && r <= b)    return node[k];
        int lx = query(a, b, 2*k+1, l, (l+r)/2);
        int rx = query(a, b, 2*k+2, (l+r)/2, r);
        return max(lx, rx);
    }
};

int main(){
    int n, w, h;
    cin >> n;
    vector<pair<int,int>> v;
    for(int i = 0; i < n; i++){
        cin >> w >> h;
        v.push_back({w,h});
    }
    sort(v.begin(), v.end(), comp);
    ST st(100001);
    for(int i = 0; i < n; i++){
        st.assign(v[i].second, 1+st.query(0, v[i].second));
    }
    cout << st.query(0, 100001) << endl;
    return 0;
}