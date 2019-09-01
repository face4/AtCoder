#include<iostream>
#include<queue>
#include<iomanip>
using namespace std;

int main(){
    int n;
    cin >> n;
    priority_queue<double> pq;
    for(int i = 0; i < n; i++){
        double x;   cin >> x;
        pq.push(-x);
    }
    while(pq.size() > 1){
        double a = -pq.top();   pq.pop();
        double b = -pq.top();   pq.pop();
        pq.push(-(a+b)/2);
    }
    cout << fixed << setprecision(12) << -pq.top() << endl;
    return 0;
}