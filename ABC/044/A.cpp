#include<iostream>
using namespace std;

int main(){
    int n, k, x, y;
    cin >> n >> k >> x >> y;

    long long ans = 0;
    ans += min(k, n) * x;
    ans += max(0, n-k) * y;
    cout << ans << endl;
    
    return 0;
}