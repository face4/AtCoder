#include<iostream>
using namespace std;
const int INF = 1e9;

int main(){
    int n;
    cin >> n;

    int h[n], ans[n+2];
    for(int i = 0; i < n; i++)  cin >> h[i], ans[i] = INF;
    
    ans[0] = 0;

    for(int i = 0; i < n; i++){
        ans[i+1] = min(ans[i+1], ans[i] + abs(h[i]-h[i+1]));
        ans[i+2] = min(ans[i+2], ans[i] + abs(h[i]-h[i+2]));
    }

    cout << ans[n-1] << endl;

    return 0;
}