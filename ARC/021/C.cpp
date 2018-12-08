#include<iostream>
#include<queue>
using namespace std;

typedef long long ll;

int main(){
    int k, n;
    cin >> k >> n;

    ll a[n], d[n];
    for(int i = 0; i < n; i++)  cin >> a[i] >> d[i];

    // 増築費の最大値を二分探索　log_2(2e11) * 10^5
    ll l = 1, r = 200000000000, cnt;
    while(r != l){
        ll mid = (l+r)/2;
        cnt = 0;
        for(int i = 0; i < n; i++){
            if(mid < a[i])  continue;
            cnt += (mid-a[i])/d[i] + 1;
        }
        if(cnt < k) l = mid+1;
        else        r = mid;
    }

    cnt = 0;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(l < a[i])  continue;
        ll tmp = (l-a[i])/d[i] + 1; // 項数
        cnt += tmp;
        
        // ans += (2*a[i] + (tmp-1)*d[i]) * tmp / 2; // 等差数列の和
        ans += a[i]*tmp + (tmp-1)*tmp/2*d[i]; // 計算順序を変えてオーバーフローを防ぐ
    }

    ans -= (cnt-k)*l; // 過剰分を引く

    cout << ans << endl;

    return 0;
}