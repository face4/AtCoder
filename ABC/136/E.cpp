// 色々な解説ブログを読んだけどあんまり腑に落ちてない
#include<iostream>
#include<numeric>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

bool ok(int x, int k, vector<int> &v){
    vector<int> y;
    for(int k : v)  y.push_back(k%x);
    sort(y.begin(), y.end());
    ll sum = accumulate(y.begin(), y.end(), 0ll);
    ll tmp = accumulate(y.begin(), y.begin()+(int)(y.size())-sum/x, 0ll);
    return tmp <= k;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i];
    int x = abs(accumulate(v.begin(), v.end(), 0));
    int ret = 1;
    for(int i = 1; i*i <= x; i++){
        if(x%i) continue;
        if(ok(i, k, v))    ret = max(ret, i);
        if(ok(x/i, k, v))  ret = max(ret, x/i);
    }
    cout << ret << endl;
    return 0;
}