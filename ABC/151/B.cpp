#include<iostream>
using namespace std;

int main(){
    int n, k, m;
    cin >> n >> k >> m;
    int sum = 0;
    for(int i = 0; i < n-1; i++){
        int x;  cin >> x;
        sum += x;
    }
    for(int i = 0; i <= k; i++){
        double tmp = sum+i;
        if(tmp/n >= m){
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}