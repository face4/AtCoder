#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool dp[100001] = {};

int main(){
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i];

    sort(v.begin(), v.end());

    for(int i = v[0]; i <= k; i++){
        for(int j = 0; j < n && v[j] <= i; j++){
            if(!dp[i-v[j]]) dp[i] = true; // able to win
        }
    }

    cout << (dp[k] ? "First" : "Second") << endl;

    return 0;
}