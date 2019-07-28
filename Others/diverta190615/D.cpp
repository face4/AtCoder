#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

// a[i] == b[i]なら意味がないので無視
int siz = 3000000;

int main(){
    ll n;
    cin >> n;
    vector<int> a(3), b(3);
    for(int i = 0; i < 3; i++)  cin >> a[i];
    for(int i = 0; i < 3; i++)  cin >> b[i];
    if(a[0]>=b[0]&&a[1]>=b[1]&&a[2]>=b[2]){
        // btoa
        vector<ll> dp(n+1, 0);
        for(int i = 0; i < 3; i++){
            if(a[i] == b[i])    continue;
            for(int j = b[i]; j <= n; j++){
                dp[j] = max(dp[j], dp[j-b[i]] + (a[i]-b[i]));
            }
        }
        ll ans = 0;
        for(int i = 0; i <= n; i++){
            ans = max(ans, dp[i]);
        }
        cout << n+ans << endl;
    }else if(a[0]<=b[0]&&a[1]<=b[1]&&a[2]<=b[2]){
        // atob      
        vector<ll> dp(n+1, 0);
        for(int i = 0; i < 3; i++){
            if(a[i] == b[i])    continue;
            for(int j = a[i]; j <= n; j++){
                dp[j] = max(dp[j], dp[j-a[i]] + (b[i]-a[i]));
            }
        }
        ll ans = 0;
        for(int i = 0; i <= n; i++){
            ans = max(ans, dp[i]);
        }
        cout << n+ans << endl;
    }else{
        vector<int> atob, btoa;
        for(int i = 0; i < 3; i++){
            if(a[i] > b[i])         btoa.push_back(i);
            else if(a[i] < b[i])    atob.push_back(i);
        }
        if(atob.size() == 1){
            int k = atob[0];
            n = n/a[k]*b[k] + n%a[k];
            // dp
            vector<ll> dp(n+1, 0);
            for(int k = 0; k < btoa.size(); k++){
                int i = btoa[k];
                for(int j = b[i]; j <= n; j++){
                    dp[j] = max(dp[j], dp[j-b[i]] + (a[i]-b[i]));
                }
            }
            ll ans = 0;
            for(int i = 0; i <= n; i++) ans = max(ans, dp[i]);
            cout << n+ans << endl;
        }else if(atob.size() == 2){
            vector<ll> dp(n+1, 0);
            for(int k = 0; k < atob.size(); k++){
                int i = atob[k];
                for(int j = a[i]; j <= n; j++){
                    dp[j] = max(dp[j], dp[j-a[i]] + (b[i]-a[i]));
                }
            }
            ll ans = 0;
            for(int i = 0; i <= n; i++) ans = max(ans, dp[i]);
            ans += n;
            if(btoa.size() == 1){
                int k = btoa[0];
                ans = ans%b[k] + ans/b[k]*a[k];
            }
            cout << ans << endl;
        }
    }

    return 0;
}