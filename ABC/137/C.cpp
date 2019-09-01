#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<string> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        sort(v[i].begin(), v[i].end());
    }
    sort(v.begin(), v.end());
    int i = 0;
    ll ans = 0;
    while(i < n){
        int r = upper_bound(v.begin(), v.end(), v[i])-v.begin();
        ans += (ll)(r-i)*(r-i-1)/2;
        i = r;
    }
    cout << ans << endl;
    return 0;
}