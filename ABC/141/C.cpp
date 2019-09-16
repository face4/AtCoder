#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
typedef long long ll;

int main(){
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> v(n, 0);
    for(int i = 0; i < q; i++){
        int x;  cin >> x;
        v[--x]++;
    }
    ll sum = accumulate(v.begin(), v.end(), 0ll);
    for(int i = 0; i < n; i++){
        cout << (sum-v[i] >= k ? "No" : "Yes") << endl;
    }
    return 0;
}