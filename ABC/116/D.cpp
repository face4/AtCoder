#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;

struct sushi{
    int t, d;
    bool operator<(const sushi other) const{
        return d < other.d;
    }
};

int main(){
    int n, k, t, d;
    cin >> n >> k;

    vector<sushi> v(n);
    for(int i = 0; i < n; i++){
        cin >> t >> d;
        v[i] = sushi({t, d});
    }
    sort(v.rbegin(), v.rend());

    ll ans = 0;
    vector<int> ate(n+1, 0);
    ll kind = 0, sum = 0;
    priority_queue<pair<int,int>> pq;

    for(int i = 0; i < k; i++){
        sum += v[i].d;
        ate[v[i].t]++;
        if(ate[v[i].t] == 1)    kind++;
        pq.push({-v[i].d, v[i].t});
    }

    ans = kind*kind + sum;

    for(int i = k; i < n; i++){
        sushi now = v[i];
        if(ate[now.t] != 0)    continue;
        while(!pq.empty()){
            auto p = pq.top();  pq.pop();
            if(ate[p.second] == 1)  continue;
            ate[p.second]--;
            ate[now.t]++;
            sum += p.first;
            sum += now.d;
            kind++;
            break;
        }
        ans = max(ans, kind*kind+sum);
    }

    cout << ans << endl;

    return 0;
}