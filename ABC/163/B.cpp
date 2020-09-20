#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

typedef long long ll;

int main(){
    int n, m;
    cin >> n >> m;
    vector<ll> v(m);
    for(int i = 0; i < m; i++)  cin >> v[i];
    ll sum = accumulate(v.begin(), v.end(), 0ll);
    cout << (sum <= n ? n-sum : -1) << endl;
    return 0;
}