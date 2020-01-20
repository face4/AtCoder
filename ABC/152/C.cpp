#include<iostream>
#include<queue>
using namespace std;

int main(){
    int n;
    cin >> n;
    int ret = 0;
    priority_queue<int> pq;
    for(int i = 0; i < n; i++){
        int x;  cin >> x;
        if(pq.empty() || -pq.top() >= x)    ret++;
        pq.push(-x);
    }
    cout << ret << endl;
    return 0;
}