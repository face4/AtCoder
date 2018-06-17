#include<iostream>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    int ans = 0;
    int x;
    for(int i = 0; i < n; i++){
        cin >> x;
        ans += 2*min(x, k-x);
    }

    cout << ans << endl;
    return 0;
}