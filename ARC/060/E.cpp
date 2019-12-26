#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int nxt[20][100000];

void construct(vector<int> &v, int l, int c[20][100000]){
    int n = v.size();
    for(int i = 0; i+1 < n; i++){
        c[0][i] = upper_bound(v.begin(),v.end(),v[i]+l)-v.begin()-1;
    }
    c[0][n-1] = -1;
    for(int k = 0; k+1 < 20; k++){
        for(int i = 0; i < n; i++){
            if(c[k][i] < 0)  c[k+1][i] = -1;
            else             c[k+1][i] = c[k][c[k][i]];
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> x(n);
    for(int i = 0; i < n; i++)  cin >> x[i];
    vector<int> y(n);
    for(int i = 0; i < n; i++)  y[i] = 1e9-x[n-1-i];
    int l;
    cin >> l;
    construct(x, l, nxt);
    auto f = [&](int a, int b)->int{
        int ret = 0, tmp = a;
        for(int k = 19; k >= 0; k--){
            int to = nxt[k][tmp];
            if(to >= 0 && to < b){
                tmp = to;
                ret += 1<<k;
            }
        }
        return ret+1;
    };
    int q;
    cin >> q;
    while(q--){
        int a, b;
        cin >> a >> b;
        a--, b--;
        if(a > b)   swap(a,b);
        cout << f(a, b) << endl;
    }
    return 0;
}
