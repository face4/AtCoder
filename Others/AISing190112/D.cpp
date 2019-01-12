// クソ汚い.サンプルは合う.
#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;
typedef long long ll;

int main(){
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++)  cin >> a[i];
    vector<ll> b(n), c(n+1);
    b[0] = a[0], b[1] = a[1];
    for(int i = 2; i < n; i++)  b[i] = b[i-2] + a[i];
    c[0] = 0;
    for(int i = 0; i < n; i++)  c[i+1] = a[i]+c[i];

    int x;
    while(q-- > 0){
        cin >> x;
        if(x > a[n-1]){
            cout << b[n-1] << endl;
            continue;
        }else if(x < a[0]){
            cout << c[n-1+1] - c[n/2-1+1] << endl;
            continue;
        }

        // aokiが+-midの範囲のカードを取るとして二分探索
        int l = 0, r = a[n-1]+1;
        int aoki, taka, s, t;
        ll ans = 0;

        int cnt = 35;
        
        while(true){
            int mid = (l+r)/2;
            auto ss = lower_bound(a.begin(), a.end(), x-mid);
            auto tt = lower_bound(a.begin(), a.end(), x+mid);
            s = ss-a.begin(), t = tt-a.begin();
            if(*tt != x+mid) t--;
            aoki = t-s+1;
            taka = n-t-1;
            // cout << "aoki takes " << a[s] << " to " << a[t] << endl;
            // cout << aoki << " " << taka << endl;
            
            if(*ss == x-mid && *tt == x+mid){
                if(aoki-1+1 == taka+1){
                    t--;
                    ll tmp = c[t+1]-c[s];
                    if(s > 0)   tmp += b[s-1];
                    ans = c[n]-tmp;
                    break;
                }
            }

            if(aoki+1 == taka){
                ll tmp = c[t+1]-c[s];
                if(s > 0)   tmp += b[s-1];
                ans = c[n]-tmp;
                break;
            }
            
            if(aoki == taka){
                ll tmp = c[t+1]-c[s];
                if(s > 1)   tmp += b[s-2];
                ans = c[n]-tmp;
                break;
            }

            if(aoki+1 > taka){
                r = mid;
            }else{
                l = mid+1;
            }
        }

        cout << ans << endl;

    }
    return 0;
}