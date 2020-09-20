#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n+1, 0), b(m+1, 0);
    for(int i = 1; i <= n; i++) cin >> a[i], a[i] += a[i-1];
    for(int i = 1; i <= m; i++) cin >> b[i], b[i] += b[i-1];
    int ans = 0;
    for(int i = 0; i <= n; i++){
        if(a[i] > k)    break;
        ans = max(ans, i+(int)(upper_bound(b.begin(),b.end(),k-a[i])-b.begin())-1);
    }
    cout << ans << endl;
    return 0;
}