#include<iostream>
#include<queue>
using namespace std;

typedef long long ll;

int main(){
    priority_queue<pair<int,int>> pq;
    
    ll h;
    int n, a, b;
    cin >> n >> h;

    for(int i = 0; i < n; i++){
        cin >> a >> b;

        pq.push({a, 1});
        pq.push({b, 0});
    }

    int ans = 0;
    ll accum = 0;
    while(1){
        auto x = pq.top();  pq.pop();

        if(x.second == 1){
            ans += (h-accum+x.first-1) / x.first;
            accum = h;
        }else{
            ans++;
            accum += x.first;
        }

        if(accum >= h)  break;
    }

    cout << ans << endl;
    return 0;
}