#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
typedef long long ll;

bool b[100001] = {};

int main(){
    vector<ll> v;
    ll n, x, m;
    cin >> n >> x >> m;
    ll ans = 0;
    while(!b[x]){
        v.push_back(x);
        b[x] = true;
        x = x*x%m;
    }
    int loopLen = 1;
    ll loopS = 0;
    int vlen = v.size();
    if(n <= vlen){
        cout << accumulate(v.begin(), v.begin()+n, 0ll) << endl;
        return 0;
    }
    while(v[vlen-loopLen] != x){
        loopS += v[vlen-loopLen];
        loopLen++;
    }
    loopS += v[vlen-loopLen];
    int fLen = vlen-loopLen;
    ans += accumulate(v.begin(), v.begin()+fLen, 0ll);
    ans += (n-fLen)/loopLen*loopS;
    for(int i = 0; i < (n-fLen)%loopLen; i++){
        ans += v[vlen-loopLen+i]%m;
    }
    cout << ans << endl;
    return 0;
}