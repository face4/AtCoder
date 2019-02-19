#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

int main(){
    int l, a;
    cin >> l;
    vector<ll> dp(5, 0);
    for(int i = 0; i < l; i++){
        cin >> a;
        vector<ll> next(5);
        next[0] = dp[0] + a;
        next[1] = min(dp[0],dp[1]) + a%2 + 2*(a==0);
        next[2] = min({dp[0], dp[1], dp[2]}) + (1-a%2);
        next[3] = min({dp[0], dp[1], dp[2], dp[3]}) + a%2 + 2*(a==0);
        next[4] = *min_element(dp.begin(), dp.end()) + a;
        dp = next;
    }
    cout << *min_element(dp.begin(), dp.end()) << endl;
    return 0;
}