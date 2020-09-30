#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const ll mod = 998244353;

int main(){
    int n, k;
    cin >> n >> k;
    int l[k], r[k];
    for(int i = 0; i < k; i++)  cin >> l[i] >> r[i];
    vector<ll> sum(n+1, 0);
    sum[1] = 1;
    for(int i = 2; i <= n; i++){
        for(int j = 0; j < k; j++){
            int from = i-r[j], to = i-l[j];
            ll F = from-1 >= 0 ? sum[from-1] : 0;
            ll T = to < 0 ? 0 : sum[to];
            sum[i] += T-F+mod;
            sum[i] %= mod;
        }
        sum[i] += sum[i-1];
        sum[i] %= mod;
    }
    cout << (sum[n]-sum[n-1]+mod)%mod << endl;
    return 0;
}