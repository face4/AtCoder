#include<iostream>
#include<queue>
using namespace std;
#define inRange(x,a,b) (a <= x && x < b)

typedef long long ll;

int main(){
    int n, k;
    cin >> n >> k;

    int a[n];
    for(int i = 0; i < n; i++)  cin >> a[i];

    priority_queue<pair<int,int>> pq;
    ll ans = 0;

    int pos = 0;

    while(pos < n){
        pq.push({-a[pos], pos});

        pair<int,int> p = pq.top();
        while(p.second <= pos-k){
            pq.pop();
            p = pq.top();
        }

        ans += -p.first;
        pos++;
    }

    cout << ans << endl;

    return 0;
}