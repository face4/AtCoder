// xがl未満でyがl以上r以下であるようなペアを余計に数えているのでダメ.
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

// equal = 0, less = 1
// pos, start, less, zeronum
ll dp[100][2][2][100];

ll f(string s){
    if(s == "") return 0;
    memset(dp, 0, sizeof(dp));
    dp[0][0][0][0] = 1;
    for(int i = 0; i < s.length(); i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                for(int l = 0; l < 70; l++){
                    if(dp[i][j][k][l] == 0) continue;
                    for(int now = 0; now <= (k||s[i]=='1'); now++){
                        int nj = j || now;
                        int nk = k || (s[i]-'0'>now);
                        int nl = l;
                        if(j > 0 && now == 0)   nl++;
                        dp[i+1][nj][nk][nl] += (dp[i][j][k][l]);
                        dp[i+1][nj][nk][nl] %= mod;
                    }
                }
            }
        }
    }
    vector<ll> beki(70, 1);
    for(int i = 1; i < 70; i++) beki[i] = beki[i-1]*2%mod;
    ll ans = 0;
    for(int l = 0; l < 70; l++){
        ans += beki[l]*dp[s.length()][1][0][l];
        ans %= mod;
        ans += beki[l]*dp[s.length()][1][1][l];
        ans %= mod;
    }
    return ans;
}

// 2^(2進表現における0の数) <- 但し、これはl=1のときにしか成り立たない
int main(){
    ll l, r;
    cin >> l >> r;
    l--;
    string ls = "", rs = "";
    while(l){
        ls += (char)('0'+l%2);
        l /= 2;
    }
    while(r){
        rs += (char)('0'+r%2);
        r /= 2;
    }
    reverse(ls.begin(), ls.end());
    reverse(rs.begin(), rs.end());
    cout << (f(rs)-f(ls)+mod)%mod << endl;
    return 0;
}