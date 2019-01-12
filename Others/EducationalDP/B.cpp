#include<iostream>
using namespace std;
const int INF = 1e9;

int main(){
    int n, k;
    cin >> n >> k;

    int h[n], ans[n+k];
    for(int i = 0; i < n; i++)  cin >> h[i], ans[i] = INF;
    
    ans[0] = 0;

    for(int i = 0; i < n; i++){
        for(int j = 1; j <= k; j++){
            if(i+j >= n)    break;
            ans[i+j] = min(ans[i+j], ans[i] + abs(h[i]-h[i+j]));
        }
    }

    cout << ans[n-1] << endl;

    return 0;
}