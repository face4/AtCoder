#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> v(m);
    for(int i = 0; i < m; i++)  cin >> v[i];
    sort(v.begin(), v.end());

    ll ans = 0;
    vector<int> diff;
    for(int i = 0; i < m-1; i++){
        ans += v[i+1]-v[i];
        diff.push_back(v[i+1]-v[i]);
    }
    sort(diff.rbegin(), diff.rend());

    for(int i = 0; i < min(n-1,m-1); i++){
        ans -= diff[i];
    }

    cout << ans << endl;

    return 0;
}