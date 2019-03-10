#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> v;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end());
    int res = m;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        int buy = min(res, v[i].second);
        ans += (ll)buy * v[i].first;
        res -= buy;
    }
    cout << ans << endl;
    return 0;
}