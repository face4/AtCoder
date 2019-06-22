#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> w(n);
    for(int i = 0; i < n; i++)  cin >> w[i];
    int r = accumulate(w.begin(), w.end(), 0)-w[0];
    int l = w[0];
    int ans = abs(r-l);
    for(int i = 1; i < n-1; i++){
        l += w[i];
        r -= w[i];
        ans = min(ans, abs(r-l));
    }
    cout << ans << endl;
    return 0;
}