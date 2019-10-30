#include<iostream>
#include<deque>
using namespace std;
typedef long long ll;
const int mod = 1000000007;

// 想定解(DP) あんまりよくわかっていない
int dp[1000001] = {};   // k駅で止まらない場合の数
int sum[1000001] = {};  // dpの累積和

int main(){
    int n, k;
    cin >> n >> k;
    dp[0] = sum[1] = 1;
    for(int i = 1; i <= n+1; i++){
        // すべてのi-k <= j < iに対して、[j, i)の区間を連続で停車し続ける可能性がある
        // ので、その数を累積和で数える
        if(i != 1 && i != n)    dp[i] = (sum[i]-sum[max(i-k,0)] + mod) % mod;
        sum[i+1] = (sum[i]+dp[i])%mod;
    }
    cout << dp[n+1] << endl;
    return 0;
}

// 自分の回答
// int main(){
//     ll n, k;
//     cin >> n >> k;
//     deque<int> d;
//     for(int i = 0; i < k; i++)  d.push_back(i==1);
//     ll sum = 1;
//     for(int i = 2; i <= n; i++){
//         d.push_front(sum);
//         sum = (sum+sum-d.back()+mod)%mod;
//         d.pop_back();
//     }
//     cout << (sum-d.front()+mod)%mod << endl;
//     return 0;
// }