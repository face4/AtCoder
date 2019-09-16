// youtubeの公式解説動画を見て
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

// A + B = A xor B + (A & B)*2

int main(){
    int n;
    cin >> n;
    vector<ll> v(n);
    ll s = 0;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        s ^= v[i];
    }
    ll ans = s; // A+B = A^B
    // sで1が立っている桁についてはどう塗り分けようがA&Bのその桁は0　
    // どう頑張ったって0なので考えない
    for(int i = 0; i < n; i++)  v[i] &= ~s; 
    
    // 掃き出し
    int rnk = 0;
    vector<int> top(61); 
    for(int i = 60; i >= 0; i--){
        int j = rnk;
        for(; j < n; j++){
            if(v[j]>>i&1){
                swap(v[rnk], v[j]);
                break;
            }
        }
        if(j == n)  continue;
        top[rnk] = i;
        for(int k = 0; k < n; k++){
            if(rnk == k)    continue;
            if(v[k]>>i&1)   v[k] ^= v[rnk];
        }
        rnk++;
    }
    
    ll x = 0;
    for(int i = 60; i >= 0; i--){
        ll nx = x + (1ll<<i);
        ll b = nx;
        for(int j = 0; j < rnk; j++){
            if(b>>top[j]&1) b ^= v[j];
        }
        if((b&nx) == 0){
            x = nx;
        }
    }
    ans += x * 2; // (A&B)*2 を足しこむ
    cout << ans << endl;
    return 0;
}