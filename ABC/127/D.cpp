#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
typedef long long ll;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++)  cin >> a[i];
    sort(a.begin(), a.end());
    vector<pair<int,int>> vp;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        vp.push_back({y, x});
    }
    sort(vp.rbegin(), vp.rend());
    int ind = 0, pos = 0;
    ll sum = 0;
    while(pos < n && ind < m){
        for(int k = 0; k < vp[ind].second && pos < n; k++){
            a[pos] = max(a[pos], vp[ind].first);
            pos++;
        }
        ind++;
    }
    cout << accumulate(a.begin(), a.end(), 0ll) << endl;
    return 0;
}