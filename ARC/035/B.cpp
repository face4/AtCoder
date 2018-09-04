#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;
const ll mod = 1e9+7;

ll fact(int n){
    ll ret = 1;
    while(n > 1){
        ret *= n--;
        ret %= mod;
    }
    return ret;
}

int main(){
    int n;
    cin >> n;

    map<int,int> appear;
    vector<int> p(n);
    for(int i = 0; i < n; i++){
        cin >> p[i];
        appear[p[i]]++;
    }
    sort(p.begin(), p.end());

    ll accum = p[0];
    for(int i = 1; i < n; i++){
        p[i] += p[i-1];
        accum += p[i];
    }

    ll pattern = 1;
    for(auto x : appear)    pattern = (pattern * fact(x.second)) % mod;

    cout << accum << endl << pattern << endl;

    return 0;
}