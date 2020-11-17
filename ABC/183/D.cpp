#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main(){
    int n, w;
    cin >> n >> w;
    priority_queue<pair<pii,int>> pq;
    for(int i = 0; i < n; i++){
        int s, t, p;
        cin >> s >> t >> p;
        pq.push({{-s, -1},p});
        pq.push({{-t, 1},p});
    }
    ll now = 0;
    while(!pq.empty()){
        auto p = pq.top();  pq.pop();
        if(p.first.second == -1){
            now += p.second;
            if(now > w){
                cout << "No" << endl;
                return 0;
            }
        }else{
            now -= p.second;
        }
    }
    cout << "Yes" << endl;
    return 0;
}