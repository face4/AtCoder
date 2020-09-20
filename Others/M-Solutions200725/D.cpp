#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)  cin >> a[i];
    vector<ll> dp(n, 1000);
    for(int i = 1; i < n; i++){
        dp[i] = dp[i-1];
        for(int j = 0; j < i; j++){
            dp[i] = max(dp[i], dp[j]/a[j]*a[i]+dp[j]%a[j]);
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
    return 0;
}