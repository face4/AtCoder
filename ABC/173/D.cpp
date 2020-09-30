#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i];
    sort(v.rbegin(), v.rend());
    priority_queue<pii> pq;
    pq.push({v[1], v[0]});
    pq.push({v[1], v[0]});
    ll ans = v[0];
    for(int i = 2; i < n; i++){
        pii p = pq.top();   pq.pop();
        ans += p.first;
        pq.push({v[i], p.first});
        pq.push({v[i], p.second});
    }
    cout << ans << endl;
    return 0;
}