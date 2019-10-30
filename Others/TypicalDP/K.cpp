#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

// 交点の右端が同じ場合は左端の元座標昇順(正負反転後降順)
// で良いので、これは{右端、左端}の単純な昇順ソートで実現できる

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> vp;
    for(int i = 0; i < n; i++){
        int x, r;
        cin >> x >> r;
        vp.push_back({x+r, x-r});
    }
    sort(vp.begin(), vp.end());
    vector<int> dp(n, INT_MAX);
    for(int i = 0; i < n; i++){
        *lower_bound(dp.begin(), dp.end(), -vp[i].second) = -vp[i].second;
    }
    cout << lower_bound(dp.begin(), dp.end(), INT_MAX)-dp.begin() << endl;
    return 0;
}
