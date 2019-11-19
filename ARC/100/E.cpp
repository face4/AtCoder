// はじめての高速ゼータ変換
// 理解度は50%くらい
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef pair<int,int> pii;

int main(){
    auto f = [](pii p, pii q)->pii{
        int a[4] = {p.first, p.second, q.first, q.second};
        sort(a, a+4);
        return {a[3], a[2]};
    };
    int n;
    cin >> n;
    vector<pii> v(1<<n, {0,0});
    for(int i = 0; i < 1<<n; i++)   cin >> v[i].first;
    for(int j = 0; j < n; j++){
        for(int i = 0; i < 1<<n; i++){
            if((i>>j)&1){
                v[i] = f(v[i], v[i&~(1<<j)]);
            }
        }
    }
    vector<int> ans(1<<n, 0);
    for(int i = 1; i < 1<<n; i++)   ans[i] = max(ans[i-1], v[i].first+v[i].second);
    for(int i = 1; i < 1<<n; i++)   cout << ans[i] << endl;
    return 0;
}