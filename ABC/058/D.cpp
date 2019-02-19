#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> x(n), y(m);
    vector<ll> sx(n+1,0), sy(m+1,0);
    for(int i = 0; i < n; i++)  cin >> x[i], sx[i+1] = sx[i]+x[i];
    for(int i = 0; i < m; i++)  cin >> y[i], sy[i+1] = sy[i]+y[i];
    ll xsum = 0, ysum = 0;
    for(int i = 1; i < n; i++){
        xsum += (ll)x[i]*i-sx[i];
        xsum %= mod;
    }
    for(int i = 1; i < m; i++){
        ysum += (ll)y[i]*i-sy[i];
        ysum %= mod;
    }
    cout << (xsum*ysum)%mod << endl;
    return 0;
}