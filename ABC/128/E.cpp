#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;

const ll INF = 1ll<<60;

int main(){
    int n, q;
    cin >> n >> q;
    vector<ll> s(n), t(n), x(n), za;
    
    for(int i = 0; i < n; i++){
        cin >> s[i] >> t[i] >> x[i];
        if(t[i]-x[i] <= 0)  continue;
        za.push_back(max(0ll,s[i]-x[i]));
        za.push_back(t[i]-x[i]);
    }

    vector<int> d(q);
    for(int i = 0; i < q; i++){
        cin >> d[i];
        za.push_back(d[i]);
    }

    sort(za.begin(), za.end());
    za.erase(unique(za.begin(), za.end()), za.end());
    auto f = [&](int val)->int{
        return lower_bound(za.begin(),za.end(),val)-za.begin();
    };

    int siz = za.size();

    vector<pair<ll,int>> st[siz];
    for(int i = 0; i < n; i++){
        if(t[i]-x[i] <= 0)  continue;
        int from = f(max(0ll,s[i]-x[i])), to = f(t[i]-x[i]);
        st[from].push_back({-x[i], to});
    }

    vector<ll> imos(siz, INF);
    // time, to
    priority_queue<pair<ll,int>> pq;


    for(int i = 0; i < siz; i++){
        for(int j = 0; j < st[i].size(); j++){
            pq.push(st[i][j]);
        }
        while(!pq.empty()){
            auto p = pq.top();
            if(i < p.second)    break;
            pq.pop();
        }
        if(!pq.empty()) imos[i] = -(pq.top()).first;
        else            imos[i] = -1;
    }

    for(int i = 0; i < q; i++){
        cout << imos[f(d[i])] << endl;
    }
    
    return 0;
}