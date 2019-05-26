#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;

// 10^6 * log(10^6)
int main(){
    int x, y, z, k;
    cin >> x >> y >> z >> k;
    vector<ll> a(x), b(y), c(z);
    
    for(int i = 0; i < x; i++)  cin >> a[i];
    for(int i = 0; i < y; i++)  cin >> b[i];
    vector<ll> xy(x*y);
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            xy[i*x+j] = (ll)a[i]+b[j];
        }
    }
    sort(xy.rbegin(), xy.rend());

    for(int i = 0; i < z; i++)  cin >> c[i];

    priority_queue<pair<ll, pair<int,int>>> pq;
    for(int i = 0; i < z; i++)  pq.push({xy[0]+c[i], {i, 0}});

    for(int i = 0; i < k; i++){
        pair<ll, pair<int,int>> p = pq.top();  pq.pop();
        cout << p.first << endl;
        int ni = p.second.first, nj = p.second.second+1;
        if(nj < x*y)    pq.push({(xy[nj]+c[ni]), {ni, nj}});
    }
    return 0;
}