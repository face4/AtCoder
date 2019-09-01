#include<iostream>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++)  cin >> a[i];
    for(int i = 0; i < n; i++)  cin >> b[i];

    priority_queue<pair<int,int>> pq;
    for(int i = 0; i < n; i++){
        if(a[i] > b[i]){
            cout << -1 << endl;
            return 0;
        }else if(a[i] < b[i]){
            pq.push({b[i], i});
        }
    }

    ll ans = 0;
    while(!pq.empty()){
        pair<int,int> p = pq.top(); pq.pop();
        int i = p.second;
        int unit = b[(i-1+n)%n] + b[(i+1)%n];
        if((b[i]-a[i])/unit == 0){
            cout << -1 << endl;
            return 0;
        }
        ans += (b[i]-a[i])/unit;
        b[i] -= (b[i]-a[i])/unit*unit;
        if(b[i] > a[i]) pq.push({b[i], i});
    }

    cout << ans << endl;
    return 0;
}