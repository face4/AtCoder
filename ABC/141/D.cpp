#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;

int main(){
    int n, m;
    cin >> n >> m;
    priority_queue<int> pq;
    for(int i = 0; i < n; i++){
        int x;  cin >> x;
        pq.push(x);
    }
    while(m-- > 0 && !pq.empty()){
        int x = pq.top();   pq.pop();
        if(x > 1)   pq.push(x/2);
    }
    ll sum = 0;
    while(!pq.empty()){
        sum += pq.top();   pq.pop();
    }
    cout << sum << endl;
    return 0;
}