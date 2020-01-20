#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++)  cin >> a[i], a[i] /= 2;
    ll x = *max_element(a.begin(), a.end());
    for(int i = 0; i < n; i++){
        x = (x+)
    }
    return 0;
}