#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++)  cin >> a[i];
    for(int i = 0; i < n; i++)  cin >> b[i];
    sort(b.begin(), b.end());
    int ans = 0;
    for(int i = 28; i >= 0; i--){
        int now = 1<<i;
        for(int j = 0; j < n; j++){
            a[j] %= now*2;
            b[j] %= now*2;
        }
        sort(b.begin(), b.end());
        ll sum = 0;
        for(int j = 0; j < n; j++){
            sum += lower_bound(b.begin(), b.end(), 2*now-a[j]) - lower_bound(b.begin(), b.end(), now-a[j]);
            sum += lower_bound(b.begin(), b.end(), 4*now-a[j]) - lower_bound(b.begin(), b.end(), 3*now-a[j]);
        }
        ans += now*(sum%2);
    }
    cout << ans << endl;
    return 0;
}