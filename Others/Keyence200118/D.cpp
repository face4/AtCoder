// 嘘っぽい
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef pair<int,int> pii;
int ans = 1<<30, a[18], b[18], n;
vector<pii> u, d;
vector<int> take, res;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)  cin >> a[i];
    for(int i = 0; i < n; i++)  cin >> b[i];
    for(int i = 0; i < n; i++){
        if(i%2 == 0)    u.push_back({a[i], i}), d.push_back({b[i], i});
        else            d.push_back({a[i], i}), u.push_back({b[i], i});
    }
    sort(u.begin(), u.end());
    sort(d.begin(), d.end());
    for(int i = 0; i < 1<<n; i++){
        vector<pii> val;
        vector<bool> used(n, 0);
        for(int j = 0; j < n; j++)  if(i>>j&1)  val.push_back(u[j]), used[u[j].second] = true;
        if(val.size() != (n+1)/2)   continue;
        vector<pii> res;
        for(int j = 0; j < n; j++){
            if(!used[j]){
                if(j%2 == 0)    res.push_back({b[j], j});
                else            res.push_back({a[j], j});
            }
        }
        sort(res.begin(), res.end());
        vector<int> value, index;
        for(int j = 0; j < n/2; j++){
            value.push_back(val[j].first);
            value.push_back(res[j].first);
            index.push_back(val[j].second);
            index.push_back(res[j].second);
        }
        if(n%2 == 1)    value.push_back(val[n/2].first), index.push_back(val[n/2].second);
        bool ok = true;
        for(int j = 1; j < n; j++)  ok &= value[j-1] <= value[j];
        if(!ok) continue;
        int tmp = 0;
        for(int j = 0; j < n; j++){
            for(int k = 0; k+1 < n-j; k++){
                if(index[k] > index[k+1]){
                    swap(index[k], index[k+1]);
                    tmp++;
                }
            }
        }
        ans = min(ans, tmp);
    }
    cout << (ans == 1<<30 ? -1 : ans) << endl;
    return 0;
}