// editorial
// 軸ごとに独立に考えられることに気付けなかったのがだめ
#include<iostream>
using namespace std;

typedef long long ll;
ll mod = 1000000007;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n, a, b;
        cin >> n >> a >> b;
        ll neg = a+b > n ? 0 : (n-a-b+2)*(n-a-b+1)%mod;
        neg = ((n-a+1)*(n-b+1)-neg+mod)%mod;
        ll ans = (n-a+1)*(n-a+1)%mod*(n-b+1)%mod*(n-b+1)-neg*neg%mod;
        cout << (ans+mod)%mod << endl;
    }
    return 0;
}