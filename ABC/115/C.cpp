#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i];
    sort(v.begin(), v.end());

    int ans = 1<<30;
    for(int i = k-1; i < n; i++){
        ans = min(ans, v[i]-v[i-k+1]);
    }

    cout << ans << endl;
    
    return 0;
}