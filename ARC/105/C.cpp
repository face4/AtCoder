#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;

typedef pair<int,int> pii;

int main(){
    int n, m;
    cin >> n >> m;
    int w[n];
    for(int i = 0; i < n; i++)  cin >> w[i];
    vector<pii> v;
    int vmin = 1<<30;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        v.push_back({b, a});
        vmin = min(vmin, b);
    }
    sort(v.begin(), v.end());
    for(int i = 1; i < m; i++){
        v[i].second = max(v[i].second, v[i-1].second);
    }
    if(*max_element(w, w+n) > vmin){
        cout << -1 << endl;
        return 0;
    }
    vector<int> d(n);
    iota(d.begin(), d.end(), 0);
    int ans = 1<<30;
    do{
        vector<int> pos(n, 0);
        vector<int> acc(n, w[d[0]]);
        for(int i = 1; i < n; i++)  acc[i] = acc[i-1]+w[d[i]];
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                int weight = acc[i]-(j>0?acc[j-1]:0);
                int ind = upper_bound(v.begin(), v.end(), make_pair(weight-1, 1<<30))-v.begin();
                if(ind == 0){
                    pos[i] = max(pos[i], pos[j]);
                }else{
                    pos[i] = max(pos[i], pos[j]+v[--ind].second);
                }
            }
        }
        ans = min(ans, pos.back());
    }while(next_permutation(d.begin(), d.end()));
    cout << ans << endl;
    return 0;
}