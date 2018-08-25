#include<iostream>
#include<climits>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    int x[n];
    for(int i = 0; i < n; i++)  cin >> x[i];

    int ans = INT_MAX;
    for(int l = 0; l <= n-k; l++){
        int r = l+k-1;
        if((x[l] < 0 && x[r] < 0) || (x[l] > 0 && x[r] > 0)){
            ans = min(ans, max(abs(x[l]), abs(x[r])));
        }else{
            ans = min(ans, 2 * min(abs(x[l]), abs(x[r])) + max(abs(x[l]), abs(x[r])) );
        }
    }

    cout << ans << endl;

    return 0;
}