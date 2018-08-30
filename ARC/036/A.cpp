#include<iostream>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    int t[n+1];
    t[0] = 0;

    for(int i = 1; i <= n; i++){
        cin >> t[i];
        t[i] += t[i-1];
    }

    int ans = -1;
    for(int i = 3; i <= n; i++){
        if(t[i] - t[i-3] < k){
            ans = i;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}