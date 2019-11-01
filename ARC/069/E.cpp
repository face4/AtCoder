#include<iostream>
#include<queue>
#include<vector>
#include<set>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    priority_queue<pair<int,int>> pq;
    for(int i = 0; i < n; i++){
        int x;  cin >> x;
        pq.push({x, -i});
    }
    vector<ll> ans(n, 0);
    set<int> inds;
    int bef;
    while(!pq.empty()){
        int now = pq.top().first;
        if(!inds.empty()){
            ans[*inds.begin()] += (ll)(bef-now)*(int)(inds.size());
        }
        while(!pq.empty() && pq.top().first == now){
            inds.insert(-pq.top().second);
            pq.pop();
        }
        bef = now;
    }
    ans[0] += (ll)bef*n;
    for(int i = 0; i < n; i++)  cout << ans[i] << endl;
    return 0;
}